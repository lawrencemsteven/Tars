#pragma once

#include <Tars/Input/InputTypes.h>

#include <map>
#include <vector>

namespace TarsBackend {
	class InputManager {
	private:
		struct KeyInfo {
			Tars::Input::State pressed = Tars::Input::State::TARS_RELEASED;
			bool changed			   = false;
		};

		std::map<Tars::Input::Key, KeyInfo> m_keys{};

		std::vector<Tars::Input::Key> m_keysToReset{};

	public:
		InputManager();
		~InputManager();

		/**
		 * @brief Get the current state of the key
		 * @param key
		 * @return The state of the key
		 */
		Tars::Input::State getKey(Tars::Input::Key key);

		/**
		 * @brief Get whether or not the current key was just pressed
		 * @param key
		 * @return pressed or not
		 */
		bool getKeyPressed(Tars::Input::Key key);

		/**
		 * @brief Get whether or not the current key was just released
		 * @param key
		 * @return released or not
		 */
		bool getKeyReleased(Tars::Input::Key key);

		/**
		 * @brief Whenever GLFW reports a key press
		 * @param key - The key pressed
		 * @param scancode - scancode
		 * @param state - The state of the key
		 * @param mods - Modifiers towards the press
		 */
		void keyCallback(Tars::Input::Key key, int scancode, Tars::Input::State state, int mods);

		/**
		 * @brief Reset the keys that were marked as just changed
		 */
		void resetChanged();
	};
}