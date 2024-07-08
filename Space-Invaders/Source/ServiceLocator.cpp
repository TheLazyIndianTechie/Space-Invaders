#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	// Constructor for service locator
	graphicService = nullptr;
	eventService = nullptr;

	createServices(); // call to instantiate
}

ServiceLocator::~ServiceLocator()
{
	// Deconstructor for service locator
	clearAllServices();

}

void ServiceLocator::createServices()
{
	// Create all services for various units
	graphicService = new GraphicService();
	eventService = new EventService();
}

void ServiceLocator::clearAllServices()
{
	// Clear all services up on destroy
	delete(graphicService);
	graphicService = nullptr;

	delete(eventService);
	eventService = nullptr;

	// Prevents dangling pointers
}

ServiceLocator* ServiceLocator::getInstance()
{
	// Method to get service locator instance
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::initialize()
{
	// Initialize services
	graphicService->initialize();
	eventService->initialize();
}

void ServiceLocator::update()
{
	// Update game state and logic for service
	graphicService->update();
	eventService->update();
}

void ServiceLocator::render()
{
	// Render services 
	graphicService->render();
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphicService;
}

EventService* ServiceLocator::getEventService()
{
	return eventService;
}