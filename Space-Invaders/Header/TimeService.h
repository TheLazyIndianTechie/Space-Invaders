#pragma once
#include <chrono>

class TimeService
{
private:
	// A point in time indicating the starting time of previous frame
	std::chrono::time_point<std::chrono::steady_clock> previousTime;

	float deltaTime; // Stores the difference delta time

	void updateDeltaTime(); // Update delta time on tick
	float calculateDeltaTime(); // calculate the difference in frame start time of each frame.
	void updatePreviousTime(); // Update time of frame to current time

public:

	// lifecycle methods
	void initialize();
	void update(); 
	// No need render because it is a service without visuals

	// getters
	float getDeltaTime();
};