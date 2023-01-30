#include <TarsPCH.h>
#include <Graphics/OpenGL/OpenGLBuffer.h>

#include <glad/glad.h>

namespace Tars {

	//////////////////////////////////////////////////////////////////////////
	// VERTEX BUFFER /////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size) {
		glGenBuffers(1, &m_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() { glDeleteBuffers(1, &m_rendererID); }

	void OpenGLVertexBuffer::bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_rendererID); }

	void OpenGLVertexBuffer::unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }


	//////////////////////////////////////////////////////////////////////////
	// INDEX BUFFER //////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count) : m_count(count) {
		glGenBuffers(1, &m_rendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() { glDeleteBuffers(1, &m_rendererID); }

	void OpenGLIndexBuffer::bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID); }

	void OpenGLIndexBuffer::unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

}
