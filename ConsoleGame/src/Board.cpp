#include "Board.h"

namespace ConGame {
	Board::Board()
	{
		content = new int[3 * 3];

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

	bool Board::CheckPosIsValid(char* pos)
	{
		return true;
	}

}
