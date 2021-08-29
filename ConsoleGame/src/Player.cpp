#include "Player.h"

ConGame::Player::Player()
	: name(""), symbol(BoardPossibilities::O)
{
}

void ConGame::Player::TurnInput()
{

}

ConGame::BoardPossibilities ConGame::Player::GetPlayerSymbol() const
{
	return symbol;
}

void ConGame::Player::SetPlayerSymbol(BoardPossibilities symbol)
{
	this->symbol = symbol;
}

std::string_view ConGame::Player::GetName() const
{
	return name;
}

void ConGame::Player::SetName(const std::string& name)
{
	this->name = name;
}
