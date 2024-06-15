#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Header/GameService.h"

using namespace std;
using namespace sf;

#pragma region BackupCode

/*
Vector2f initialPosition;

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
		movementSpeed = 0.5f;
		playerPosition = Vector2f(initialPosition);
		playerSprite.setPosition(playerPosition);
	}

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


	void setPosition(Vector2f position) {
		playerPosition = position;
	}

	void takeDamage(){
		
	}

	void movePlayer(float offsetX) {
		playerPosition.x += offsetX;

	}

	void shootBullets() {

	}

};

int main() {

	// Define the video mode
	VideoMode videoMode = VideoMode(800, 600);

	// Create window object with dimensions
	RenderWindow window(videoMode, "Face Invader");

	// Set start position of window
	initialPosition = sf::Vector2f(window.getSize().x / 2, window.getSize().y - 100);


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
			player.movePlayer(-1.0 * player.getMovementSpeed());
		}

		if (Keyboard::isKeyPressed(movePlayerRight))
		{
			// Move player right
			cout << "Player is being moved right" << endl;
			player.movePlayer(1.0 * player.getMovementSpeed());
		}

		// Set origin to the center of the texture
		player.playerSprite.setOrigin(player.playerTexture.getSize().x / 2.f, player.playerTexture.getSize().y / 2.f);

		Vector2f startPos = Vector2f(window.getSize().x / 2, window.getSize().y - player.playerTexture.getSize().y);
		// cout << "Player Sprite Height: " << player.playerTexture.getSize().y << endl;

		
		// Clear the window with Yellow
		window.clear(Color::Yellow);
		

		player.playerSprite.setPosition(player.getPosition());

		// Print player speed 
		//cout << "Player Movement Speed: " << player.getMovementSpeed() << endl;


		// Draw player
		window.draw(player.playerSprite);

		// Display to window
		window.display();
	}

	return 0;
}
*/
#pragma endregion

int main() {
	//TODO: 
	// Comment previous code
	// Include GameService in this file
	// Create object of type GameService
	// Call ignite to initialize
	// While gameservice is running, call update and render

	// Create GameService object
	GameService gameService;

	// Initialize game
	gameService.ignite();

	// Check if game service is running
	while (gameService.isRunning())
	{
		// Update game state
		gameService.update();
		
		// Render frames
		gameService.render();
	}


	return 0;
}