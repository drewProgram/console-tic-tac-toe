#pragma once

#include <string>

#include "BoardEnums.h"

namespace ConGame {
	class Player
	{
	private:
		std::string name;
		Identifiers::BoardPossibilities symbol;

	public:
		Player();

		Identifiers::BoardPossibilities GetPlayerSymbol() const;
		void SetPlayerSymbol(Identifiers::BoardPossibilities symbol);
		std::string_view GetName() const;
		void SetName(const std::string& name);
	};
}