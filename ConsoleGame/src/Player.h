#pragma once

#include <string>

#include "Board.h"
#include "Game.h"

namespace ConGame {
	class Player
	{
	private:
		std::string name;
		PlayerSymbol symbol;

	public:
		Player()
			: name(""), symbol(PlayerSymbol::O)
		{}

		void TurnInput();

		PlayerSymbol GetPlayerSymbol() const;
		void SetPlayerSymbol(PlayerSymbol symbol);
		char* GetName() const;
		void SetName(const std::string& name);
	};
}