#include "GraphicService.h"

void GraphicService::setVideoMode()
{
	videoMode = new sf::VideoMode(windowHeight, windowWidth, sf::VideoMode::getDesktopMode().bitsPerPixel);
}

void GraphicService::OnDestroy()
{
	delete(videoMode);
	delete(window);
}

GraphicService::GraphicService()
{
	videoMode = nullptr;
	window = nullptr;
}

GraphicService::~GraphicService()
{
	OnDestroy();
}

sf::RenderWindow* GraphicService::createGameWindow()
{
	setVideoMode();
	return new sf::RenderWindow(*videoMode, windowTitle);

}

void GraphicService::initialize()
{
	window = createGameWindow();
}

void GraphicService::update()
{
}

void GraphicService::render()
{
}

bool GraphicService::isGameWindowOpen()
{
	return getGameWindow()->isOpen();
}

sf::RenderWindow* GraphicService::getGameWindow()
{
	return window;
}

sf::Color GraphicService::getWindowColor()
{
	return windowColor;
}
