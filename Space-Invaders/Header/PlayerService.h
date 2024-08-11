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
	sf::Vector2f playerPosition;
	
	// Player texture variables
	const sf::String playerTexturePath = "assets/textures/player_ship.png";

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	// Render window
	sf::RenderWindow* gameWindow;


	//Player methods
	void initializePlayerSprite();
	void processPlayerInput();
	

	


public:
	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();

	void movePlayerLeft();
	void movePlayerRight();
	
	float getMovementSpeed();
	sf::Vector2f getPosition();

};