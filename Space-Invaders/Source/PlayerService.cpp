#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"


PlayerService::PlayerService()
{
	gameWindow = nullptr;
	
	health = 3;
	score = 0;
	movementSpeed = 5;
	sf::Vector2f playerPosition = getPosition();
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
	processPlayerInput();
}

void PlayerService::render()
{
	gameWindow->draw(playerSprite);
}

void PlayerService::initializePlayerSprite()
{

	// Set sprite
	if (playerTexture.loadFromFile(playerTexturePath))
	{
		std::cout << "Texture loaded successfully: " << playerTexture.getSize().x << " x " << playerTexture.getSize().y << std::endl;

		playerSprite.setTexture(playerTexture);
		std::cout << "Player sprite set successfully" << std::endl;
	}
	else
	{
		std::cout << "Player sprite could not be loaded"<<std::endl;
	}
}

void PlayerService::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();

	if (event_service->isKeyboardEvent())
	{
		if (event_service->pressedLeftKey())
		{
			std::cout << "Player has pressed left key. trying to move player left" << std::endl;
			movePlayer(-1.0 * getMovementSpeed());
		}

		if (event_service->pressedRightKey()) 
		{
			std::cout << "Player has pressed right key. trying to move player right" << std::endl;
			movePlayer(1.0 * getMovementSpeed());
		}
	}
}

void PlayerService::movePlayer(float offsetX)
{
	std::cout << "Moving Player " << getMovementSpeed();
	playerPosition.x += offsetX;
	playerSprite.setPosition(playerPosition);
}

float PlayerService::getMovementSpeed()
{
	return movementSpeed;
}

sf::Vector2f PlayerService::getPosition()
{
	return playerPosition;
}
