#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Player
{

	//TODO: Create properties for player class :
	// 1. sf::texture and sf::sprite
	// 2. int player score
	// 3. int health
	// 4. int movement speed
	// 5. sf::Vector2f position

private: 
	int health;
	int score;
	float movementSpeed;

public: 
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2f playerPosition;

	//Create constructor
	Player() {
		health = 100;
		score = 0;
		movementSpeed = 5.0f;
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

int main() {

	// Define the video mode
	VideoMode videoMode = VideoMode(800, 600);

	// Create window object with dimensions
	RenderWindow window(videoMode, "Face Invader");




	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			// Check for clicks to close event
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		// Clear the window with Yellow
		window.clear(Color::Color::Yellow);
		
		// Initialize the player
		Player player;

		// Print player speed 
		cout << "Player Movement Speed: " << player.getMovementSpeed() << endl;

		// Display to window
		window.display();
	}

	return 0;
}