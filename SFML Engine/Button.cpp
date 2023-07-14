#include "Button.h"

void Button::onClick(sf::RenderWindow* w)
{
	if (clicked == false || only_once == false)
	{
		if(Clickable::onClick(w))
			clicked = true;
	}
}