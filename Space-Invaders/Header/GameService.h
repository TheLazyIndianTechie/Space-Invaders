#pragma once

class GameService {

private:
	// Initialize game
	void Initialize();
	
	// Handle cleanup tasks
	void Destroy();

public:
	// Constructor game service
	GameService(); 

	// Destructor game service
	~GameService();

	void ignite(); // Starts the initialization
	void update(); // This is the main tick
	void render(); // Renders every frame
	bool isRunning(); // Checks if game is running

};