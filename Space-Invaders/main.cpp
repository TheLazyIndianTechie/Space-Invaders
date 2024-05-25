#include <./SFML/Graphics.hpp>

int main()
{
    // Defining the video mode dimensions
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Spawn a window object with dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "Lazy SMFL Window");

    return 0;
}