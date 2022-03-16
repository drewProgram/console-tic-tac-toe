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
		Board& board;
		Player* currentPlayer;

	public:
		// you cant make an array of references on c++
		std::array<Player, 2> players;

		Game(Board& board);
	
		void StartTurn();
		void Update();
		void Render();
		
		bool GetGameOver() const;
		void SetGameOver();
		void SetCurrentCoord(char* coord);
		std::string GetCurrentCoord() const;

		Player* GetCurrentPlayer() const;
		void SetCurrentPlayer(Player* player);

		void AssertCoordIsValid(char* coord);
	};
}

