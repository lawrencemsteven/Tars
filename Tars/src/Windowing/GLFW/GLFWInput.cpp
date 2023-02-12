#include <TarsPCH.h>
#include <Windowing/GLFW/GLFWInput.h>

#include <GLFW/glfw3.h>
#include <Tars/Main/Application.h>

namespace Tars {

	Input* Input::s_instance = new GLFWInput();

	bool GLFWInput::isKeyPressedImpl(int keycode) {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state	= glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool GLFWInput::isMouseButtonPressedImpl(int button) {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state	= glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> GLFWInput::getMousePositionImpl() {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return {(float)xpos, (float)ypos};
	}

	float GLFWInput::getMouseXImpl() {
		auto [x, y] = getMousePositionImpl();
		return x;
	}

	float GLFWInput::getMouseYImpl() {
		auto [x, y] = getMousePositionImpl();
		return y;
	}

}