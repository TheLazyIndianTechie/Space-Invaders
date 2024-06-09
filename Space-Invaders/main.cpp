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
		movementSpeed = 4.0f;
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

	void takeDamage(){
		
	}

	void movePlayer() {

	}

	void shootBullets() {

	}

};

int main() {

	// Define the video mode
	VideoMode videoMode = VideoMode(800, 600);

	// Create window object with dimensions
	RenderWindow window(videoMode, "Face Invader");

	// Initialize the player
	Player player;

	// Set sprite
	if (player.playerTexture.loadFromFile("./assets/textures/player_ship.png"))
	{
		std::cout << "Texture loaded successfully: " << player.playerTexture.getSize().x << " x " << player.playerTexture.getSize().y;

		player.playerSprite.setTexture(player.playerTexture);
	}
	else
	{
		std::cout << "Player sprite could not be loaded";
	}

	// Set up player input controls
	Keyboard::Key movePlayerLeft = Keyboard::Left; 
	Keyboard::Key movePlayerRight = Keyboard::Right;

	

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

		// Capture player input
		if (Keyboard::isKeyPressed(movePlayerLeft))
		{
			// Move player left
			cout << "Player is being moved left" << endl;
		}

		if (Keyboard::isKeyPressed(movePlayerRight))
		{
			// Move player right
			cout << "Player is being moved right" << endl;
		}

		// Clear the window with Yellow
		window.clear(Color::Color::Yellow);
		
		
		// Print player speed 
		//cout << "Player Movement Speed: " << player.getMovementSpeed() << endl;

		// Display to window
		window.display();
	}

	return 0;
}