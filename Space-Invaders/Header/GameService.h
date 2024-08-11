#pragma once
#include <SFML/Graphics.hpp>
#include "../Header/ServiceLocator.h"


class GameService {

private:

	ServiceLocator* serviceLocator; 
	sf::RenderWindow* gameWindow;
	
	// Initialize game
	void initialize();
	void InitializeVariables();
	void destroy();

public:
	// Constructor game service
	GameService(); 

	// Destructor game service
	~GameService();

	void ignite(); // Starts the initialization
	void update(); // This is the main tick
	void render(); // Renders every frame
	bool isRunning(); // Checks if game is running

};