#pragma once

#include <GLFW/glfw3.h>

#include <iostream>

namespace TarsEngine {
	class Window {
	private:
		uint32_t m_width{1280};
		uint32_t m_height{720};

		GLFWwindow* m_window;

	public:
		Window(std::string_view applicationName);
		~Window();

		/**
		 * Query whether GLFW states the window should close.
		 * @return Whether or not the window should close.
		 */
		bool shouldClose();

		/**
		 * Poll GLFW Events
		 */
		void pollEvents();
	};
}
