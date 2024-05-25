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


    // Draw a Green Circle
    CircleShape greenCircle; // Create a circle shape
    greenCircle.setFillColor(Color::Green); // Fill with green
     
    // Draw a Red Square
    RectangleShape redSquare; // Define a rectangle shape for the square
    redSquare.setFillColor(Color::Red); // Fill with red

    // Draw a Blue Triangle
    ConvexShape blueTriangle; // Create a convex shape for the triangle
    blueTriangle.setFillColor(Color::Blue); // Fill with Blue
    
    

    //TODO: Code to set the object at centre
    //setPosition((window.getSize().x - circle.getRadius() * 2) / 2, (window.getSize().y - circle.getRadius() * 2) / 2);
    
    
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
