#include "TextButton.h"

void TextButton::update(float dt)
{
	return;
}

void TextButton::render(sf::RenderWindow* w)
{
	w->draw(*this);
	Button::onClick(w);
}