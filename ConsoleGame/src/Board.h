#pragma once

#include <array>

/*
* TODO: Create relation between string and Enum
*/

namespace ConGame {
	enum class BoardPossibilities {
		Empty = 0,
		X,
		O
	};

	enum class BoardCoords {
		A1 = 0,
		A2,
		A3,
		B1,
		B2,
		B3,
		C1,
		C2,
		C3
	};

	class Board
	{
	private:
		int* content;

	public:
		explicit Board();
		~Board();
		Board(const Board& other) = delete;

		void PopulateBoard();
		
		bool CheckPosIsValid(char* pos);

		int* const GetContent() const;
	};
}