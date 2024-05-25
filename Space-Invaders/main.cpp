#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
    // Define the video mode dimensions
    VideoMode videoMode(320*1.5, 480*1.5);

    // Spawn a window object with dimensions and a title
    RenderWindow window(videoMode, "The Trifecta");

    // Enabling vSync
    window.setVerticalSyncEnabled(true);


    // Draw a Green Circle
    CircleShape greenCircle; // Create a circle shape
    greenCircle.setFillColor(Color::Green); // Fill with green
    greenCircle.setRadius(50); // Set radius 
    Vector2f centrePoint = Vector2f((window.getSize().x - greenCircle.getRadius() * 2) / 2, (window.getSize().y - greenCircle.getRadius() * 2) / 2); //Calculate centrepoint
    greenCircle.setPosition(centrePoint); // Centre the circle
     
    // Draw a Red Square
    RectangleShape redSquare; // Define a rectangle shape for the square
    redSquare.setFillColor(Color::Red); // Fill with red
    redSquare.setSize(Vector2f(50,50)); // Set the square size
    Vector2f offset(100, 100);
    redSquare.setPosition(centrePoint);

    // Draw a Blue Triangle
    ConvexShape blueTriangle; // Create a convex shape for the triangle
    blueTriangle.setFillColor(Color::Blue); // Fill with Blue
    blueTriangle.setPointCount(3); // Set 3 points for the polygon for a triangle
    blueTriangle.setPoint(0, Vector2f(0, 0)); // Set pos of vert 1
    blueTriangle.setPoint(1, Vector2f(1, 0)); // Set pos of vert 2
    blueTriangle.setPoint(2, Vector2f(0.5, 1)); // Set pos of vert 3
    blueTriangle.setScale(Vector2f(100, 100));
    blueTriangle.setPosition(centrePoint);
    

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

        //// Move the cube
        //cube.move(squareVelocity);

        //// Check for collisions with the window edges and reverse velocity if needed
        //if (cube.getPosition().x < 0 || cube.getPosition().x + cube.getSize().x > window.getSize().x) {
        //    squareVelocity.x = -squareVelocity.x;
        //}
        //if (cube.getPosition().y < 0 || cube.getPosition().y + cube.getSize().y > window.getSize().y) {
        //    squareVelocity.y = -squareVelocity.y;
        //}

        
        // Move the circle
        /*circle.move(circleVelocity); */

        //TODO: Check how to implement DRY here as it is repeating
        // TODO: The circle is still clipping through in the bottom. Need to research bounds and fix.
        // Check for collisions with the window edges and reverse velocity if needed
       /* if (circle.getPosition().x < 0 || circle.getPosition().x + circle.getLocalBounds().width > window.getSize().x) {
            circleVelocity.x = -circleVelocity.x;
        }
        if (circle.getPosition().y < 0 || circle.getPosition().y + circle.getLocalBounds().top > window.getSize().y) {
            circleVelocity.y = -circleVelocity.y;
        }*/


        // Clear the window
        window.clear(Color::Yellow);

        window.draw(greenCircle);
        window.draw(redSquare);
        window.draw(blueTriangle);


        // Display the drawn items
        window.display();
    }

    return 0;
}
