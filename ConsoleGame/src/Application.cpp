#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Board.h"

#ifdef _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

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
		p1.SetPlayerSymbol(PlayerSymbol::X);
		p2.SetPlayerSymbol(ConGame::PlayerSymbol::O);

		std::cout << "Player 1 set to X. Player 2 is now O." << std::endl;
	}
	else
	{
		p1.SetPlayerSymbol(PlayerSymbol::O);
		p2.SetPlayerSymbol(ConGame::PlayerSymbol::X);

		std::cout << "Player 1 set to O. Player 2 is now X." << std::endl;
	}

	std::cout << "Let the game begin!" << std::endl;
	game->players[0] = p1;
	game->players[1] = p2;

	// game loop
	while (!game->GetGameOver())
	{
		game->StartTurn();
		game->Update();
		game->Render(board);
	}

	delete board;
	delete game;

	return 0;
}