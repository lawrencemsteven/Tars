#pragma once


#include <Tars/Window.h>

#include <GLFW/glfw3.h>

namespace Tars {

	class WindowUsingGLFW : public Window {
	public:
		WindowUsingGLFW(const WindowProps& props);
		virtual ~WindowUsingGLFW();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_data.width; }
		inline unsigned int getHeight() const override { return m_data.height; }

		// Window Attributes
		inline void setEventCallback(const EventCallbackFn& callback) override {
			m_data.eventCallback = callback;
		}
		void setVSync(bool enabled) override;
		bool isVSync() const override;

		inline virtual void* getNativeWindow() const override { return m_window; }

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

	private:
		GLFWwindow* m_window;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData m_data;
	};

}