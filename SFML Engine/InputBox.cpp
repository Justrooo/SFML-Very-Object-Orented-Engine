#include "InputBox.h"

void InputBox::catchText(int char_typed)
{
	if (char_typed == ENTER_KEY)
	{
		is_active = false;
	}
	else if (char_typed != DELETE_KEY && text.size() <= limit)
	{
		text += static_cast<char>(char_typed);
	}
	else
	{
		if (!text.empty())
		{
			// Delete one character from text when DELETE_KEY pressed
			text = text.substr(0, text.size() - 1); // Pretty complicated
		}
	}
	setString(text);

}

void InputBox::update(float dt)
{
	std::cout << std::boolalpha << is_active << std::endl;
	if (is_active) 
	{
		// Animation with '_' underscore
		if (animation.getElapsedTime().asSeconds() < 1)
		{
			animation_going = true;
			setString(text + '_');
		}
		else if (animation.getElapsedTime().asSeconds() < 2)
		{
			animation_going = false;
			setString(text);
		}
		else
		{
			animation_going = false;
			animation.restart();
		}
	}
}

void InputBox::handleEvents(sf::Event& event)
{
	if (event.type == sf::Event::TextEntered && event.text.unicode < 128 && is_active)
	{
		catchText(event.text.unicode);
	}
}

void InputBox::render(sf::RenderWindow* w)
{
	if (Clickable::onClick(w))
	{
		is_active = true;
	}
	else if (Clickable::isClicking() && !Clickable::isHovering(w))
	{
		is_active = false;
		if (animation_going) setString(text);
	}

	w->draw(*this);
}                      