#include "Tars/Input/InputManager.h"

namespace TarsBackend {
	InputManager::InputManager() {
		for (Tars::Input::Key key : Tars::Input::AllKeys) {
			m_keys[key] = KeyInfo{};
		}
	}

	InputManager::~InputManager() {}

	Tars::Input::State InputManager::getKey(Tars::Input::Key key) {
		return m_keys[key].pressed;
	}

	bool InputManager::getKeyPressed(Tars::Input::Key key) {
		return m_keys[key].changed && m_keys[key].pressed == Tars::Input::PRESSED;
	}

	bool InputManager::getKeyReleased(Tars::Input::Key key) {
		return m_keys[key].changed && m_keys[key].pressed == Tars::Input::RELEASED;
	}

	void InputManager::keyCallback(Tars::Input::Key key, int scancode, Tars::Input::State state,
								   int mods) {
		if (state == Tars::Input::REPEATED)
			return;

		m_keys[key].pressed = state;
		m_keys[key].changed = true;

		m_keysToReset.push_back(key);
	}

	void InputManager::resetChanged() {
		for (Tars::Input::Key key : m_keysToReset) {
			m_keys[key].changed = false;
		}

		m_keysToReset.clear();
	}
}
