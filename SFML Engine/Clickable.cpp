#include "Clickable.h"

bool Clickable::onClick(sf::RenderWindow* w)
{
	if (isHovering(w) && clock.getElapsedTime().asSeconds() > cooldown)
	{
		if (isClicking())
		{
			if (lambda != nullptr) lambda(); // Call lambda if not nullptr (empty)
			clock.restart();
			return true;
		}
		return false;
	}
	return false;
}

bool Clickable::isClicking()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;
	else return false;
}

bool Clickable::isHovering(sf::RenderWindow* w)
{
	if (this->contains(sf::Mouse::getPosition(*w).x, sf::Mouse::getPosition(*w).y))
		return true;
	else return false;
}
