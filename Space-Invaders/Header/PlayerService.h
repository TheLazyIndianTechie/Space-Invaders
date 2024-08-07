#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class PlayerService
{

private:
	
	// Player data variables
	int health;
	int score;
	float movementSpeed;
	sf::Vector2f playerPosition;
	
	// Player texture variables
	const sf::String playerTexturePath = "../assets/textures/player_ship.png";

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	// Render window
	sf::RenderWindow* gameWindow;

	// Player transform variables
	/*sf::Vector2f playerPosition;
	sf::Vector2f initialPosition;*/


	//Player methods
	void initializePlayerSprite();
	void processPlayerInput();
	
	
	/*void setPosition(sf::Vector2f position) {
		playerPosition = position;
	}

	void takeDamage() {

	}

	void movePlayer(float offsetX) {
		playerPosition.x += offsetX;

	}

	void shootBullets() {

	}*/

public:
	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();

	void movePlayer(float offsetX);
	float getMovementSpeed();
	sf::Vector2f getPosition();

	/*sf::Vector2f getPosition() {
		return playerPosition;
	}

	float getMovementSpeed() {
		return movementSpeed;
	}

	int getHealth() {
		return health;
	}

	int getScore() {
		return score;
	}

	void setPosition(sf::Vector2f position) {
		playerPosition = position;
	}

	void takeDamage() {

	}

	void movePlayer(float offsetX) {
		playerPosition.x += offsetX;

	}

	void shootBullets() {

	}


*/

};

//Player::Player()
//{
//	health = 100;
//	score = 0;
//	movementSpeed = 0.5f;
//	playerPosition = sf::Vector2f(initialPosition);
//	playerSprite.setPosition(playerPosition);
//}
//
//Player::~Player()
//{
//}