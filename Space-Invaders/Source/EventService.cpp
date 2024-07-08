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
	return false;
}


bool EventService::isGameWindowOpen()
{
	return false;
}

bool EventService::gameWindowWasClosed()
{
	return false;
}

bool EventService::hasQuitGame()
{
	return isKeyboardEvent() && pressedEscapeKey(); // Emitted only if both are true
}