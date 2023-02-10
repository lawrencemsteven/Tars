#include <TarsPCH.h>
#include <Tars/Application.h>

#include <glad/glad.h>

#include <Tars/Input.h>

namespace Tars {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	static GLenum shaderDataTypeToOpenGLBaseType(ShaderDataType type) {
		switch (type) {
			case ShaderDataType::Float: return GL_FLOAT;
			case ShaderDataType::Float2: return GL_FLOAT;
			case ShaderDataType::Float3: return GL_FLOAT;
			case ShaderDataType::Float4: return GL_FLOAT;
			case ShaderDataType::Mat3: return GL_FLOAT;
			case ShaderDataType::Mat4: return GL_FLOAT;
			case ShaderDataType::Int: return GL_INT;
			case ShaderDataType::Int2: return GL_INT;
			case ShaderDataType::Int3: return GL_INT;
			case ShaderDataType::Int4: return GL_INT;
			case ShaderDataType::Bool: return GL_BOOL;
		}

		TARS_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	Application::Application() {
		TARS_CORE_ASSERT(!s_instance, "Application already exists!");
		s_instance = this;

		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(onEvent));

		m_imGuiLayer = new ImGuiLayer();
		pushOverlay(m_imGuiLayer);

		glGenVertexArrays(1, &m_vertexArray);
		glBindVertexArray(m_vertexArray);

		// clang-format off
		float vertices[5 * 4] = {
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f, 0.0f
		};
		// clang-format on

		m_vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));

		{
			BufferLayout layout = {{ShaderDataType::Float3, "a_Position"},
								   {ShaderDataType::Float2, "a_UV"}};

			m_vertexBuffer->setLayout(layout);
		}

		uint32_t index	   = 0;
		const auto& layout = m_vertexBuffer->getLayout();
		for (const auto& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.getComponentCount(),
								  shaderDataTypeToOpenGLBaseType(element.type),
								  element.normalized ? GL_TRUE : GL_FALSE, layout.getStride(),
								  (const void*)element.offset);
			index++;
		}

		// clang-format off
		unsigned int indices[6] = {
			0, 2, 1,
			0, 3, 2
		};
		// clang-format on

		m_indexBuffer.reset(IndexBuffer::create(indices, std::size(vertices)));

		std::string vertexSrc = R"(
			#version 450 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec2 a_UV;

			out vec2 v_UV;

			void main()
			{
				gl_Position = vec4(a_Position, 1.0);
				v_UV = a_UV;
			}
		)";

		std::string fragmentSrc = R"(
			#version 450 core

			out vec4 FragColor;

			uniform sampler2D screen;
			in vec2 v_UV;

			void main()
			{
				FragColor = texture(screen, v_UV);
			}
		)";

		m_shader.reset(new Shader(vertexSrc, fragmentSrc));

		const char* computeShaderSource = R"(
			#version 450 core
			layout(local_size_x = 16, local_size_y = 8, local_size_z = 1) in;
			layout(rgba32f, binding = 0) uniform image2D screen;

			uniform vec4 myColor;

			void main()
			{
				vec4 pixel = myColor;
				ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);

				imageStore(screen, pixel_coords, pixel);
			}
		)";

		GLuint computeShader = glCreateShader(GL_COMPUTE_SHADER);
		glShaderSource(computeShader, 1, &computeShaderSource, 0);
		glCompileShader(computeShader);

		GLint isCompiled = 0;
		glGetShaderiv(computeShader, GL_COMPILE_STATUS, &isCompiled);
		TARS_CORE_ASSERT(isCompiled == GL_TRUE, "Compute Shader Compilation Failed!")

		m_computeProgram = glCreateProgram();
		glAttachShader(m_computeProgram, computeShader);
		glLinkProgram(m_computeProgram);

		glGenTextures(1, &m_texture0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_texture0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, m_window->getWidth(), m_window->getHeight(), 0,
					 GL_RGBA, GL_FLOAT, NULL);
		glBindImageTexture(0, m_texture0, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);

		float myFloats[4] = {0.2f, 0.8f, 0.2f, 1.0f};
		GLint myLoc		  = glGetUniformLocation(m_computeProgram, "myColor");
		glProgramUniform4fv(m_computeProgram, myLoc, 1, myFloats);
	}


	Application::~Application() {}


	void Application::pushLayer(Layer* layer) { m_layerStack.pushLayer(layer); }


	void Application::pushOverlay(Layer* layer) { m_layerStack.pushOverlay(layer); }


	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin();) {
			(*--it)->onEvent(e);
			if (e.handled) break;
		}
	}


	void Application::run() {
		while (m_running) {

			glUseProgram(m_computeProgram);
			glDispatchCompute(floor(m_window->getWidth() / 16), floor(m_window->getHeight() / 8), 1);
			glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

			glClear(GL_COLOR_BUFFER_BIT);
			m_shader->bind();
			glBindVertexArray(m_vertexArray);
			glDrawElements(GL_TRIANGLES, m_indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_layerStack)
				layer->onUpdate();

			m_imGuiLayer->begin();
			for (Layer* layer : m_layerStack)
				layer->onImGuiRender();
			m_imGuiLayer->end();

			m_window->onUpdate();
		};
	}


	bool Application::onWindowClosed(WindowCloseEvent& e) {
		m_running = false;
		return true;
	}
}