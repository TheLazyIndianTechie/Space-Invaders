#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	// Constructor for service locator
	graphicService = nullptr;
	createServices();
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
	createServices();
}

void ServiceLocator::clearAllServices()
{
	// Clear all services up on destroy
	delete(graphicService);
	graphicService = nullptr;
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
}

void ServiceLocator::update()
{
	// Update game state and logic for service
	graphicService->update();
}

void ServiceLocator::render()
{
	// Render services 
	graphicService->render();
}

GraphicService* ServiceLocator::getGraphicService()
{
	graphicService;
}