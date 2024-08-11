#pragma once
#include <SFML/Graphics.hpp>

enum class PlayerState
{
	ALIVE,
	DEAD,
};


class PlayerModel
{
private:
	
	sf::Vector2f currentPlayerPosition;
	sf::Vector2f initialPlayerPosition = sf::Vector2f(400.f, 400.f);
	
	PlayerState currentPlayerState;

	int playerScore = 0;

public:
	const sf::Vector2f leftBoundaryPosition = sf::Vector2f(50.0f, 0.0f);
	const sf::Vector2f rightBoundaryPosition = sf::Vector2f(700.0f, 0.0f);
	
	const float playerMovementSpeed = 400.0f;

	PlayerModel();
	~PlayerModel();

	void initialize();
	void reset();


	// Setters
	void setPlayerPosition(sf::Vector2f position);
	void setPlayerState(PlayerState state);
	void setPlayerScore(int score);

	// Getters
	sf::Vector2f getPlayerPosition();
	PlayerState getPlayerState();
	int getPlayerScore();

};