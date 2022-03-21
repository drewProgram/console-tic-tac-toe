#include "Game.h"

namespace ConGame {
	Game::Game(Board& board)
		: gameOver(false),
		validInputs({ "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3" }),
		board(board),
		currentPlayer(),
		winner()
	{
	}

	void Game::StartTurn()
	{
		std::cout << "\nYour turn, " << currentPlayer->GetName() << "!";
		std::cout << "\nChoose a valid coordinate you want to play: ";
		std::string coord;

		AssertCoordIsValid(coord);

		SetCurrentCoord(coord);
	}

	void Game::Update()
	{
		board.SetContent(currentCoord, currentPlayer);
		board.SetMovesCount();

		if (CheckGameOver())
		{
			SetGameOver();
		}

		SetCurrentPlayer();
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

	void Game::SetCurrentCoord(std::string& coord)
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

	void Game::SetCurrentPlayer()
	{
		if (playerQueue.empty())
		{
			for (Player* player : players)
			{
				playerQueue.push(player);
			}
		}

		currentPlayer = playerQueue.front();
		playerQueue.pop();
	}

	void Game::AssertCoordIsValid(std::string& coord)
	{
		bool isInputValid = false;
		bool isInputAvailable = false;
		while (!isInputAvailable)
		{
			std::cin >> coord;

			for (std::string_view position : validInputs)
			{
				if (position.find(coord) != std::string::npos)
				{
					isInputValid = true;

					if (board.CheckCoordIsAvailable(coord))
					{
						isInputAvailable = true;
						break;
					}
				}
			}

			if (!isInputValid)
			{
				std::cout << "You must choose a valid coordinate!! (A1, A2, B1...)" << std::endl;
				continue;
			}

			if (!isInputAvailable)
			{
				std::cout << "This position already have a symbol!!" << std::endl;
				isInputValid = false;
			}
		}
	}

	bool Game::CheckGameOver()
	{
		if (board.GetMovesCount() == 9)
		{
			winner = Identifiers::BoardPossibilities::Empty;
			return true;
		}

		return false;
	}

	void Game::DrawGameOverScreen()
	{
		std::cout << "\nGamer Over!" << std::endl;

		if (winner == Identifiers::BoardPossibilities::Empty)
		{
			std::cout << "It was a tie! Good effort, everyone. Play again to have a real winner!";
		}
	}
}
