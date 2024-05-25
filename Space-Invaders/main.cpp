#include <SFML/Graphics.hpp>

int main()
{
    // Define the video mode dimensions
    sf::VideoMode videoMode(320, 480);

    // Spawn a window object with dimensions and a title
    sf::RenderWindow window(videoMode, "Lazy Bouncing Cube");

    // Enabling vSync
    window.setVerticalSyncEnabled(true);

    // Create a rectangle shape representing the cube
    sf::RectangleShape cube(sf::Vector2f(50, 50));
    cube.setFillColor(sf::Color::Black);
    cube.setPosition(135, 215); // Initial position

    // Set initial velocity for the cube
    sf::Vector2f velocity(0.75f, 0.75f);

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check window closure
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Move the cube
        cube.move(velocity);

        // Check for collisions with the window edges and reverse velocity if needed
        if (cube.getPosition().x < 0 || cube.getPosition().x + cube.getSize().x > window.getSize().x) {
            velocity.x = -velocity.x;
        }
        if (cube.getPosition().y < 0 || cube.getPosition().y + cube.getSize().y > window.getSize().y) {
            velocity.y = -velocity.y;
        }

        // Clear window
        window.clear(sf::Color::Yellow);

        // Draw the cube
        window.draw(cube);

        // Display the drawn items
        window.display();
    }

    return 0;
}
