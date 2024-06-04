#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Player
{

};

int main() {

// Define the video mode
	VideoMode videoMode = VideoMode(800, 600);

	// Create window object with dimensions
	RenderWindow window(videoMode, "SFML Window");


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

		window.display();
	}

	return 0;
}