#include "Game.h"

ConGame::Game::Game()
	: gameOver(false)
{
	validInputs = {
		"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"
	};
}

void ConGame::Game::StartTurn()
{
	std::cout << "Choose a valid coordinate you want to play: ";
	char* coord;
	std::cin >> coord;
}

void ConGame::Game::Update()
{
	
}

void ConGame::Game::Render(const Board* board)
{
	// writing board on screen
	char index = 64;

	std::cout << "    1  2  3" << std::endl;
	for (int y = 0; y < 3; y++)
	{
		index++;
		std::cout << index << "   ";

		for (int x = 0; x < 3; x++)
		{
			std::cout << board->GetContent()[y + x * 3] << "  ";
		}
		std::cout << std::endl;
	}
}

bool ConGame::Game::GetGameOver() const
{
	return gameOver;
}
