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
	currentPlayerState = PlayerState::ALIVE;
	currentPlayerPosition = initialPlayerPosition;
	playerScore = 0;
}

void PlayerModel::setPlayerPosition(sf::Vector2f position)
{
	currentPlayerPosition = position;
}

void PlayerModel::setPlayerState(PlayerState state)
{
	currentPlayerState = state;
}

void PlayerModel::setPlayerScore(int score)
{
	playerScore = score;
}

sf::Vector2f PlayerModel::getPlayerPosition()
{
	return currentPlayerPosition;
}

PlayerState PlayerModel::getPlayerState()
{
	return currentPlayerState;
}

int PlayerModel::getPlayerScore()
{
	return playerScore;
}


