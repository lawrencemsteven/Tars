#pragma once

#include <Tars/Input/InputManager.h>

#include <iostream>

namespace TarsBackend {
	class Window {
	private:
		uint32_t m_width{1280};
		uint32_t m_height{720};

		GLFWwindow* m_window;

		inline static TarsBackend::InputManager m_inputManager{};

	public:
		Window(std::string_view applicationName);
		~Window();

		/**
		 * @brief Get the required extensions for the Window for the Graphics API
		 * @return The required extensions
		 */
		static std::pair<uint32_t, const char**> getRequiredExtensions();

		/**
		 * @brief Get Window Handle
		 * @return Window Handle
		 */
		HWND getHWND();

		/**
		 * @brief Query whether GLFW states the window should close.
		 * @return Whether or not the window should close.
		 */
		bool shouldClose();

		/**
		 * @brief Poll GLFW Events
		 */
		void pollEvents();

		/**
		 * @brief Gets the current state of the key
		 * @param key
		 * @return true if the key is currently down, false otherwise
		 */
		bool getKey(Tars::Input::Key key);

		/**
		 * @brief Gets whether or not the current key has been Pressed
		 * @param key
		 * @return True if the key has just been pressed
		 */
		bool getKeyPressed(Tars::Input::Key key);

		/**
		 * @brief Gets whether or not the current key has been Released
		 * @param key
		 * @return True if the key has just been released
		 */
		bool getKeyReleased(Tars::Input::Key key);

	private:
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}
