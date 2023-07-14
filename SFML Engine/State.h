#pragma once
#include "SimpleDrawable.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class State // Abstract class for representing a state like menu, game, pause etc
{
protected:
	// Resources
	std::map<std::string, Object*> objects;

public:
	State() {};
	virtual ~State() = 0 {};

	// Public virtual functions
	virtual void update(float dt) = 0; // Update state
	virtual void render(sf::RenderWindow* w) = 0; // Render state

	virtual void handleEvents(sf::Event& event) = 0;
};