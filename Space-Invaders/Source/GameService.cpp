#include <iostream>
#include "../Header/GameService.h"
#include "../Header/GraphicService.h"

using namespace std;


GameService::GameService()
{
	//Constructor
	serviceLocator = nullptr;
	gameWindow = nullptr;
	
}

GameService::~GameService()
{
	//Destructor 
	destroy();
}


void GameService::ignite()
{
	// Call the initialization and starts game
	serviceLocator = ServiceLocator::getInstance();
	initialize();
}

void GameService::initialize()
{
	// Initialize the game;
	serviceLocator->initialize();
	InitializeVariables();

}

void GameService::InitializeVariables()
{
	gameWindow = serviceLocator->getGraphicService()->getGameWindow();
}

void GameService::destroy()
{
	// End the app

}


void GameService::update()
{
	serviceLocator->update();

}

void GameService::render()
{
	// Clear window
	gameWindow->clear(serviceLocator->getGraphicService()->getWindowColor());

	// Render the window and objects
	serviceLocator->render();

	// Display the content
	gameWindow->display();
}

bool GameService::isRunning()
{
	// Checks if game services is running
	return false;
}


