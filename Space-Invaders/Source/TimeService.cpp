#include "../Header/TimeService.h"


void TimeService::initialize()
{
	previous_time = std::chrono::steady_clock::now();
	deltaTime = 0;
}

void TimeService::update()
{
	updateDeltaTime();
}

float TimeService::getDeltaTime()
{
	return deltaTime;
}

void TimeService::updateDeltaTime()
{
	deltaTime = calculateDeltaTime();
	updatePreviousTime();
}

float TimeService::calculateDeltaTime()
{
	// Calculate time difference in microseconds 
	// wtf is happening here?

	int delta = std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::steady_clock::now() - previousTime).count();

	return static_cast<float>(delta) / static_cast<float>(1000000);
}

void TimeService::updatePreviousTime()
{
	previousTime = std::chrono::steady_clock::now();
}