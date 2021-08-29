#include "Board.h"

namespace ConGame {
	Board::Board() :
		availablePos
		{
			{ BoardCoords::A1, true },
			{ BoardCoords::A2, true },
			{ BoardCoords::A3, true },
			{ BoardCoords::B1, true },
			{ BoardCoords::B2, true },
			{ BoardCoords::B3, true },
			{ BoardCoords::C1, true },
			{ BoardCoords::C2, true },
			{ BoardCoords::C3, true },
		},
		content(new int[3 * 3])
	{
		PopulateBoard();
	}

	int* const Board::GetContent() const
	{
		return content;
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
				content[x + y * 3] = (int)BoardPossibilities::Empty;
			}
		}
	}

	bool Board::CheckPosIsValid(std::string_view pos)
	{
		return true;
	}

}
