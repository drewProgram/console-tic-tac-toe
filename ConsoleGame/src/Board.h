#pragma once

#include <array>
#include <map>
#include <string>

#include "Player.h"

#include "BoardEnums.h"

namespace ConGame {
	class Board
	{
	private:
		std::map<Identifiers::BoardCoords, bool> availablePos;
		std::map<std::string, Identifiers::BoardCoords> stringBoardCoords;
		std::array<int, 3 * 3> contentIndex;
		int* content;

	public:
		explicit Board();
		~Board();
		Board(const Board& other) = delete;

		void PopulateBoard();
		
		int* const GetContent() const;
		void SetContent(std::string coord, Player* currentPlayer);

		bool CheckCoordIsAvailable(char* coord) const;
	};
}