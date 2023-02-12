#pragma once

#include <Tars/Main/Core.h>

namespace Tars {

	class Item {
	public:
		Item();
		~Item();

		void operator++();

		uint8_t getAmount() { return m_amount; }

	private:
		uint8_t m_amountMax;
		uint8_t m_amount;
	};

}