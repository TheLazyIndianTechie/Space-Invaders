#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class PlayerService
{

private:
	
	// Player data variables
	int health = 5;
	int score = 0;
	float movementSpeed = 3.0f;
	sf::Vector2f playerPosition = sf::Vector2f(200.0f, 100.0f);
	
	// Player texture variables
	const sf::String playerTexturePath = "assets/textures/player_ship.png";

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	// Render window
	sf::RenderWindow* gameWindow;


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

};