#pragma once

#include <Tars/Renderer/Buffer.h>

namespace Tars {

	//////////////////////////////////////////////////////////////////////////
	// VERTEX BUFFER /////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	class OpenGLVertexBuffer : public VertexBuffer {
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void bind() const;
		virtual void unbind() const;

		virtual void setLayout(const BufferLayout& layout) override { m_layout = layout; };
		virtual const BufferLayout& getLayout() const override { return m_layout; };

	private:
		uint32_t m_rendererID;
		BufferLayout m_layout;
	};


	//////////////////////////////////////////////////////////////////////////
	// INDEX BUFFER //////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual uint32_t getCount() const { return m_count; }

	private:
		uint32_t m_rendererID;
		uint32_t m_count;
	};

}