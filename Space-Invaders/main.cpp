#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
    // Define the video mode dimensions
    VideoMode videoMode(320*1.5, 480*1.5);

    // Spawn a window object with dimensions and a title
    RenderWindow window(videoMode, "Lazy Bouncing Cube");

    // Enabling vSync
    window.setVerticalSyncEnabled(true);

    // Create a rectangle shape representing the cube
    RectangleShape cube(Vector2f(50, 50));
    cube.setFillColor(Color::Black);
    cube.setPosition(135, 215); // Initial position

    // Add a circle shape with a radius of 50
    CircleShape circle(50); 
    circle.setPosition((window.getSize().x - circle.getRadius() * 2) / 2, (window.getSize().y - circle.getRadius() * 2) / 2);
    circle.setFillColor(Color::Transparent);
    circle.setOutlineColor(Color::Red);
    circle.setOutlineThickness(2.0);

    // Set initial velocity for the cube
    Vector2f squareVelocity(0.75f, 0.75f);

    // Set initial velocity for circle
    Vector2f circleVelocity(-0.25f,-0.25f);

    // Game loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            // Check window closure
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Move the cube
        cube.move(squareVelocity);

        // Check for collisions with the window edges and reverse velocity if needed
        if (cube.getPosition().x < 0 || cube.getPosition().x + cube.getSize().x > window.getSize().x) {
            squareVelocity.x = -squareVelocity.x;
        }
        if (cube.getPosition().y < 0 || cube.getPosition().y + cube.getSize().y > window.getSize().y) {
            squareVelocity.y = -squareVelocity.y;
        }

        
        // Move the circle
        /*circle.move(circleVelocity); */

        //TODO: Check how to implement DRY here as it is repeating
        // TODO: The circle is still clipping through in the bottom. Need to research bounds and fix.
        // Check for collisions with the window edges and reverse velocity if needed
        if (circle.getPosition().x < 0 || circle.getPosition().x + circle.getLocalBounds().width > window.getSize().x) {
            circleVelocity.x = -circleVelocity.x;
        }
        if (circle.getPosition().y < 0 || circle.getPosition().y + circle.getLocalBounds().top > window.getSize().y) {
            circleVelocity.y = -circleVelocity.y;
        }



        // Clear window
        window.clear(Color::Yellow);


        // Draw the circle
        window.draw(circle);

        // Draw the cube
        window.draw(cube);


        // Display the drawn items
        window.display();
    }

    return 0;
}
