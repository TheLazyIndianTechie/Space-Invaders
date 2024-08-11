#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Header/GameService.h"

using namespace std;
using namespace sf;

int main() {
	//TODO: 
	// Comment previous code
	// Include GameService in this file
	// Create object of type GameService
	// Call ignite to initialize
	// While gameservice is running, call update and render

	// Create GameService object
	GameService* gameService = new GameService;
	// Initialize game
	gameService->ignite();

	// Check if game service is running
	while (gameService->isRunning())
	{
		// Update game state
		gameService->update();
		
		// Render frames
		gameService->render();
	}

	return 0;
}