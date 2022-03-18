#include <iostream>
#include <memory>

#include "Player.h"
#include "Game.h"
#include "Board.h"

#include "Log.h"

#include "BoardEnums.h"

int main()
{
	std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

	std::unique_ptr<ConGame::Board> board = std::make_unique<ConGame::Board>();
	std::unique_ptr<ConGame::Game> game = std::make_unique<ConGame::Game>(*board.get());
	ConGame::Player p1; 
	ConGame::Player p2;

	char symbol;
	std::cout << "Player 1, which symbol do you choose? (O or X)" << std::endl;
	std::cin >> symbol;
	if (symbol == 'X' || symbol == 'x')
	{
		p1.SetPlayerSymbol(Identifiers::BoardPossibilities::X);
		p2.SetPlayerSymbol(Identifiers::BoardPossibilities::O);

		std::cout << "Player 1 set to X. Player 2 is now O." << std::endl;
	}
	else
	{
		p1.SetPlayerSymbol(Identifiers::BoardPossibilities::O);
		p2.SetPlayerSymbol(Identifiers::BoardPossibilities::X);

		std::cout << "Player 1 set to O. Player 2 is now X." << std::endl;
	}

	std::string name;
	std::cout << "Player 1, what is your name? ";
	std::cin >> name;
	p1.SetName(name);
	std::cout << "\nHello, " << name << "!" << std::endl;
	std::cout << "And what about you, Player 2? What's your name? ";
	std::cin >> name;
	p2.SetName(name);
	std::cout << "\nOkay, hello " << name << "!" << std::endl;

	std::cout << "Let the game begin!" << std::endl;
	game->players[0] = p1;
	game->players[1] = p2;

	game->SetCurrentPlayer();

	game->Render();

	// game loop
	while (!game->GetGameOver())
	{
		game->StartTurn();
		game->Update();
		game->Render();
	}

	return 0;
}