#include "GuiButton.h"

void GuiButton::render(sf::RenderWindow* w)
{
	w->draw(*this);
	Button::onClick(w);
}