#pragma once

#include <iostream>
#include <array>
#include <string>

#include "Board.h"
#include "Player.h"

namespace ConGame {
	class Game
	{
	private:
		bool gameOver;
		std::string currentCoord;
		std::array<std::string_view, 9> validInputs;

	public:
		// you cant make an array of references on c++
		std::array<Player*, 2> players;

		Game();
	
		void StartTurn();
		void Update();
		void Render(const Board* board);
		
		bool GetGameOver() const;
		void SetGameOver();
		void SetCurrentCoord(std::string& coord);
		std::string GetCurrentCoord() const;
	};
}

