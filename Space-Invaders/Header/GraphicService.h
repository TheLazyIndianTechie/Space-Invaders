#pragma once
#include <SFML/Graphics.hpp>

class GraphicService {

private:
	// Setup constants
	const std::string windowTitle = "The Lazy Invader";
	const int windowHeight = 800;
	const int windowWidth = 600;

	const sf::Color windowColor = sf::Color::Yellow;

	// Define the video mode
	sf::VideoMode* videoMode;
	// Create window object with dimensions
	sf::RenderWindow* window;

	void setVideoMode(); // method to set video mode
	void OnDestroy(); // Method OnDestroy to call during deconstructor


public:

	GraphicService(); // Graphic service constructor
	~GraphicService(); // Graphic Service desconstructor and cleanup

	// Method to create window
	sf::RenderWindow* createGameWindow();

	void initialize();
	void update();
	void render();
	bool isGameWindowOpen();

	sf::RenderWindow* getGameWindow();
	sf::Color getWindowColor();

};