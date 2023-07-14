#pragma once
#include "GameState.h"

class Window : sf::RenderWindow // Class for managing window and states
{
	// Window
	sf::Event event;

	// DeltaTime
	sf::Clock clock;
	float dt;

	// All the states
	std::stack<State*> states;

	// Private functions
	void update();
	void render();

public:
	Window(std::string name = "SFML!");
	~Window();

	// Public functions
	void run(); // Window loop
};