#pragma once

#include <string>

#include "Board.h"
#include "Game.h"

namespace ConGame {
	class Player
	{
	private:
		std::string name;
		BoardPossibilities symbol;

	public:
		Player();

		void TurnInput();

		BoardPossibilities GetPlayerSymbol() const;
		void SetPlayerSymbol(BoardPossibilities symbol);
		std::string_view GetName() const;
		void SetName(const std::string& name);
	};
}