#pragma once
#include "State.h"

class GameState : public State // A class representing a state of game
{
public:
	GameState();
	virtual ~GameState() override;
	
	// Public virtual functions
	virtual void update(float dt) override; // Update state
	virtual void render(sf::RenderWindow* w) override; // Render state

	virtual void handleEvents(sf::Event& event) override;
};