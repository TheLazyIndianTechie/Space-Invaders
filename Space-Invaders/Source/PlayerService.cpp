#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"


PlayerService::PlayerService()
{
	gameWindow = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::initialize()
{
	// Get game window from Service Locator and initialize player sprite
	gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerService::update()
{
}

void PlayerService::render()
{
}

void PlayerService::initializePlayerSprite()
{
}

void PlayerService::processPlayerInput()
{
}

void PlayerService::movePlayer(float offsetX)
{
}

float PlayerService::getMovementSpeed()
{
	return 0.0f;
}

sf::Vector2f PlayerService::getPosition()
{
	return sf::Vector2f();
}
