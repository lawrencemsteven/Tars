#include <TarsPCH.h>
#include <Tars/Renderer/Buffer.h>

#include <Tars/Renderer/Renderer.h>

#include <Graphics/OpenGL/OpenGLBuffer.h>

namespace Tars {

	//////////////////////////////////////////////////////////////////////////
	// VERTEX BUFFER /////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size) {
		switch (Renderer::getAPI()) {
			case RendererAPI::None:
				TARS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
				return nullptr;
			case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		TARS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	//////////////////////////////////////////////////////////////////////////
	// INDEX BUFFER //////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	IndexBuffer* IndexBuffer::create(uint32_t* indices, uint32_t size) {
		switch (Renderer::getAPI()) {
			case RendererAPI::None:
				TARS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
				return nullptr;
			case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}

		TARS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}