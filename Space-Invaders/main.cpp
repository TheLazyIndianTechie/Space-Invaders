#include <./SFML/Graphics.hpp>

int main()
{
    // Defining the video mode dimensions. Setting it to portrait mode - Similar to an original iPhone
    sf::VideoMode videoMode = *(new sf::VideoMode(320, 480));

    // Spawn a window object with dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "Lazy SMFL Window");

    // Game loop
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Check window closure
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }

            // Clear window
            window->clear(sf::Color::Yellow);


            // Display for drawn item
            window->display();
        }
    }

    return 0;
}