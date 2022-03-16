#include "Board.h"

#include <iostream>

namespace ConGame {
	Board::Board() :
		availablePos
		{
			{ Identifiers::BoardCoords::A1, true },
			{ Identifiers::BoardCoords::A2, true },
			{ Identifiers::BoardCoords::A3, true },
			{ Identifiers::BoardCoords::B1, true },
			{ Identifiers::BoardCoords::B2, true },
			{ Identifiers::BoardCoords::B3, true },
			{ Identifiers::BoardCoords::C1, true },
			{ Identifiers::BoardCoords::C2, true },
			{ Identifiers::BoardCoords::C3, true },
		},
		stringBoardCoords
		{
			{ "A1", Identifiers::BoardCoords::A1 },
			{ "A2", Identifiers::BoardCoords::A2 },
			{ "A3", Identifiers::BoardCoords::A3 },
			{ "B1", Identifiers::BoardCoords::B1 },
			{ "B2", Identifiers::BoardCoords::B2 },
			{ "B3", Identifiers::BoardCoords::B3 },
			{ "C1", Identifiers::BoardCoords::C1 },
			{ "C2", Identifiers::BoardCoords::C2 },
			{ "C3", Identifiers::BoardCoords::C3 },
		},
		content(new int[3 * 3])
	{
		PopulateBoard();
	}

	Board::~Board()
	{
		delete[] content;
	}

	void Board::PopulateBoard()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				content[x + y * 3] = (int)Identifiers::BoardPossibilities::Empty;
				contentIndex[y + x] = x + y * 3;
			}
		}
	}

	int* const Board::GetContent() const
	{
		return content;
	}

	void Board::SetContent(std::string coord, Player* currentPlayer)
	{
		int val = (int)stringBoardCoords[coord];
		content[contentIndex[val]] = (int)currentPlayer->GetPlayerSymbol();
	}

	bool Board::CheckCoordIsAvailable(char* coord) const
	{
		auto it = stringBoardCoords.find(coord);

		if (it != stringBoardCoords.end())
		{
			Identifiers::BoardCoords chosenCoord = it->second;

			bool isCoordAvailable = availablePos.find(chosenCoord)->second;

			if (isCoordAvailable)
			{
				return true;
			}

			return false;
		}

		throw;
	}
}
