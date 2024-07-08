#include "../Header/EventService.h"
#include "../Header/GameService.h"
#include "../Header/GraphicService.h"



EventService::EventService()
{
	gameWindow = nullptr;
}

EventService::~EventService() = default;

void EventService::initialize()
{
	gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}

void EventService::update()
{
}

void EventService::processEvents()
{
	if (gameWindow->isOpen())
	{
		while (gameWindow->pollEvent(gameEvent)) {
			// Check window closed
			if (gameWindowWasClosed || hasQuitGame)
			{
				gameWindow->close(); //Close the window from service locator
			}
		}
	}
}

bool EventService::isKeyboardEvent()
{
	return gameEvent.type == sf::Event::KeyPressed; // Returns only if event type is a key press 
}

bool EventService::pressedEscapeKey()
{
	return gameEvent.key.code == sf::Keyboard::Escape;
}


bool EventService::isGameWindowOpen()
{
	return gameWindow != nullptr; // Returns only if gamewindow is pointing to a variable. Once the variable is assigned, isGameWindow will be populated. Makes sense
}

bool EventService::gameWindowWasClosed()
{
	return gameEvent.type == sf::Event::Closed;
}

bool EventService::hasQuitGame()
{
	return isKeyboardEvent() && pressedEscapeKey(); // Emitted only if both are true
}