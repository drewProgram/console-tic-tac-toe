#include "Player.h"

namespace ConGame {
	Player::Player()
		: name(""), symbol(Identifiers::BoardPossibilities::O)
	{
	}

	Identifiers::BoardPossibilities Player::GetPlayerSymbol() const
	{
		return symbol;
	}

	void Player::SetPlayerSymbol(Identifiers::BoardPossibilities symbol)
	{
		this->symbol = symbol;
	}

	std::string_view Player::GetName() const
	{
		return name;
	}

	void Player::SetName(const std::string& name)
	{
		this->name = name;
	}
}
