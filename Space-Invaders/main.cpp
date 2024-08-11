#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Header/GameService.h"

int main() {
	
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