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
		std::cout << "Texture loaded successfully: " << playerTexture.getSize().x << " x " << playerTexture.getSize().y;

		playerSprite.setTexture(playerTexture);

		// Set origin to the center of the texture
		playerSprite.setOrigin(playerTexture.getSize().x / 2.f, playerTexture.getSize().y / 2.f);

	}
	else
	{
		std::cout << "Player sprite could not be loaded";
	}
}

void PlayerService::processPlayerInput()
{
	// Set up player input controls
	sf::Keyboard::Key movePlayerLeft = sf::Keyboard::Left;
	sf::Keyboard::Key movePlayerRight = sf::Keyboard::Right;

	// Capture player input
	if (sf::Keyboard::isKeyPressed(movePlayerLeft))
	{
		// Move player left
		std::cout << "Player is being moved left" << std::endl;
		movePlayer(-1.0 * getMovementSpeed());
	}

	if (sf::Keyboard::isKeyPressed(movePlayerRight))
	{
		// Move player right
		std::cout << "Player is being moved right" << std::endl;
		movePlayer(1.0 * getMovementSpeed());
	}
}

void PlayerService::movePlayer(float offsetX)
{
	playerPosition.x += offsetX;
}

float PlayerService::getMovementSpeed()
{
	return movementSpeed;
}

sf::Vector2f PlayerService::getPosition()
{
	return playerPosition;
}
