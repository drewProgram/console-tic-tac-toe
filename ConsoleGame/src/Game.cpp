#include "Game.h"

#include "BoardEnums.h"

namespace ConGame {
	Game::Game(Board& board)
		: gameOver(false),
		validInputs({ "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3" }),
		currentCoord(""),
		board(board),
		currentPlayer(nullptr)
	{
	}

	void Game::StartTurn()
	{
		std::cout << "\nChoose a valid coordinate you want to play: ";
		char* coord = new char[sizeof(char) * 3];

		AssertCoordIsValid(coord);

		SetCurrentCoord(std::string(coord));

		// array of data - need to use delete[]
		delete[] coord;
	}

	void Game::Update()
	{
		board.SetContent(currentCoord, currentPlayer);

		if (CheckPlayerWon())
		{
			SetGameOver();
		}

		//SetCurrentPlayer(&players[1]);
	}

	void Game::Render()
	{
		char index = 64; // 64 is @, at 65 starts the alphabet (A)

		std::cout << "    1  2  3" << std::endl;
		for (int y = 0; y < 3; y++)
		{
			index++;
			std::cout << index << "   ";

			for (int x = 0; x < 3; x++)
			{
				switch (board.GetContent()[x + y * 3])
				{
				case (int)Identifiers::BoardPossibilities::Empty:
					std::cout << "   ";
					break;

				case (int)Identifiers::BoardPossibilities::O:
					std::cout << "O  ";
					break;

				case (int)Identifiers::BoardPossibilities::X:
					std::cout << "X  ";
					break;

				default:
					break;
				}
			}
			std::cout << std::endl;
		}
	}

	bool Game::GetGameOver() const
	{
		return gameOver;
	}

	void Game::SetGameOver()
	{
		gameOver = true;
	}

	void Game::SetCurrentCoord(std::string coord)
	{
		currentCoord = coord;
	}

	std::string Game::GetCurrentCoord() const
	{
		return currentCoord;
	}

	Player* Game::GetCurrentPlayer() const
	{
		return currentPlayer;
	}

	void Game::SetCurrentPlayer(Player* player)
	{
		currentPlayer = player;
	}

	void Game::AssertCoordIsValid(char* coord)
	{
		bool isInputValid = false;
		while (!isInputValid)
		{
			std::cin >> coord;

			for (std::string_view s : validInputs)
			{
				if (s.find(coord) != std::string::npos)
				{
					if (board.CheckCoordIsAvailable(coord))
					{
						isInputValid = true;
						break;
					}
				}
			}

			if (!isInputValid)
			{
				std::cout << "You must choose a valid coordinate!! (A1, A2, B1...)" << std::endl;
			}
		}
	}

	bool Game::CheckPlayerWon()
	{
		return true;
	}
}
