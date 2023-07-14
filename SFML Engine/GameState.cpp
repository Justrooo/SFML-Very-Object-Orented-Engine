#include "GameState.h"
#include "TextButton.h"
#include "GuiButton.h"
#include "SimpleText.h"
#include "InputBox.h"

GameState::GameState()
{
}

GameState::~GameState()
{
	if (!objects.empty())
	{
		for (auto& element : objects)
		{
			delete element.second;
		}
	}
}

void GameState::update(float dt)
{
	if (!objects.empty())
	{
		for (auto& element : objects)
		{
			element.second->update(dt); // polymorphism !!!
		}
	}
}

void GameState::render(sf::RenderWindow* w)
{
	if (!objects.empty())
	{
		for (auto& element : objects)
		{
			element.second->render(w); // polymorphism !!!
		}
	}
}

void GameState::handleEvents(sf::Event& event)
{
	// Handle input
	for (auto& element : objects)
	{
		element.second->handleEvents(event);
	}
}