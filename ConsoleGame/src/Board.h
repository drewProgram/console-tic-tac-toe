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
		int movesCount;
		int* content;

	public:
		explicit Board();
		~Board();
		Board(const Board& other) = delete;

		void PopulateBoard();
		
		int* const GetContent() const;
		void SetContent(std::string coord, Player* currentPlayer);

		void SetBoardAvailability(Identifiers::BoardCoords coord);

		bool CheckCoordIsAvailable(std::string& coord);

		int GetMovesCount() const;
		void SetMovesCount();
	};
}