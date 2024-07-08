#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header/GameService.h"
using namespace sf;

class Player
{

private:
	int health;
	int score;
	float movementSpeed;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2f playerPosition;
	sf::Vector2f initialPosition;

	void setPosition(Vector2f position) {
		playerPosition = position;
	}

	void takeDamage() {

	}

	void movePlayer(float offsetX) {
		playerPosition.x += offsetX;

	}

	void shootBullets() {

	}

public:
	Player();
	~Player();

	Vector2f getPosition() {
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


};

Player::Player()
{
}

Player::~Player()
{
}