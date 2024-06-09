#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


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
		movementSpeed = 4.0f;
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
		}

		if (Keyboard::isKeyPressed(movePlayerRight))
		{
			// Move player right
			cout << "Player is being moved right" << endl;
		}

		// Set origin to the center of the texture
		player.playerSprite.setOrigin(player.playerTexture.getSize().x / 2.f, player.playerTexture.getSize().y / 2.f);

		Vector2f startPos = Vector2f(window.getSize().x / 2, window.getSize().y - player.playerTexture.getSize().y);
		cout << "Player Sprite Height: " << player.playerTexture.getSize().y;

		// Set start position
		player.setPosition(startPos);
		
		// Clear the window with Yellow
		window.clear(Color::Yellow);
		
		
		// Print player speed 
		//cout << "Player Movement Speed: " << player.getMovementSpeed() << endl;


		// Draw player
		window.draw(player.playerSprite);

		// Display to window
		window.display();
	}

	return 0;
}