#include "../../Header/Player/PlayerModel.h"


PlayerModel::PlayerModel()
{
	
}

PlayerModel::~PlayerModel()
{
}

void PlayerModel::initialize()
{
	reset(); // Just reset data on initializing
}

void PlayerModel::reset()
{
	isPlayerAlive = true;
	currentPlayerPosition = initialPlayerPosition;
	playerScore = 0;
}

void PlayerModel::setPlayerPosition(sf::Vector2f position)
{
	currentPlayerPosition = position;
}

void PlayerModel::setPlayerAlive(bool alive)
{
	isPlayerAlive = alive;
}

sf::Vector2f PlayerModel::getPlayerPosition()
{
	return currentPlayerPosition;
}

bool PlayerModel::getPlayerAlive()
{
	return isPlayerAlive;
}

