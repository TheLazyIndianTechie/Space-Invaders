#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class EventService
{
private:
	sf::Event gameEvent; // An event in a game
	sf::RenderWindow* gameWindow; // game window pointer

	// Check gameplay events
	bool isGameWindowOpen();
	bool gameWindowWasClosed();
	bool hasQuitGame();

	


public:
	EventService(); // Constructor for event service
	~EventService(); // Destructor for event service

	void initialize();
	void update();
	void processEvents();
	bool pressedEscapeKey();
	bool isKeyboardEvent();
	bool pressedLeftKey();
	bool pressedRightKey();

};