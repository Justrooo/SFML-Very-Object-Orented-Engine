#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
#include <sstream>
#include <functional>
#include <iostream>

class Object // Object abstract class represents something that is updatable, as well as renderable (I couldn't come up with a better name)
{
public:
	virtual ~Object() = 0 {};

	virtual void update(float dt) = 0;
	virtual void render(sf::RenderWindow* w) = 0;
	virtual void handleEvents(sf::Event& event) = 0;
};