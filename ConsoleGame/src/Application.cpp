#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Log.h"

int main()
{
	using namespace ConGame;

	std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

	Game* game = new Game();
	Board* board = new Board();
	Player p1; 
	Player p2;

	char symbol;
	std::cout << "Player 1, which symbol do you choose? (O or X)" << std::endl;
	std::cin >> symbol;
	if (symbol == 'X' || symbol == 'x')
	{
		p1.SetPlayerSymbol(BoardPossibilities::X);
		p2.SetPlayerSymbol(BoardPossibilities::O);

		std::cout << "Player 1 set to X. Player 2 is now O." << std::endl;
	}
	else
	{
		p1.SetPlayerSymbol(BoardPossibilities::O);
		p2.SetPlayerSymbol(BoardPossibilities::X);

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
	game->players[0] = &p1;
	game->players[1] = &p2;

	// game loop
	while (!game->GetGameOver())
	{
		game->StartTurn();
		game->Update();
		game->Render(board);

		game->SetGameOver();
	}

	delete board;
	delete game;

	return 0;
}