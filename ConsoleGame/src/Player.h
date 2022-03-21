#pragma once

#include "BoardEnums.h"

#include <string>
#include <vector>

namespace ConGame {
	class Player
	{
	private:
		std::string name;
		Identifiers::BoardPossibilities symbol;
		Identifiers::BoardCoords mostRecentMove;

	public:
		Player();

		Identifiers::BoardPossibilities GetPlayerSymbol() const;
		void SetPlayerSymbol(Identifiers::BoardPossibilities symbol);
		std::string_view GetName() const;
		void SetName(const std::string name);

		Identifiers::BoardCoords GetMostRecentMove() const;
		void SetMostRecentMove(const Identifiers::BoardCoords coord);
	};
}