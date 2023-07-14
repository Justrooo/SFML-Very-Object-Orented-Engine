#pragma once
#include "TextElement.h"
#include "Clickable.h"

#define DELETE_KEY 8
#define ENTER_KEY 13

class InputBox : public TextElement, private Clickable
{
	bool is_active;
	int limit; // If character limit = -1 then it has no limit
	std::string text;
	sf::Clock animation;
	bool animation_going = false;

	void catchText(int char_typed);
public:
	InputBox(const std::string font_path = "default_font.ttf", const std::string text = "InputBox", float x = 0.f, float y = 0.f, int character_limit = 60, bool active = false)
		: TextElement{ font_path, text, x, y }, Clickable{nullptr, TextElement::getGlobalBounds(), 0.0}, limit{character_limit}, is_active{active}
	{}

	virtual void update(float dt) override;
	virtual void handleEvents(sf::Event& event) override;
	virtual void render(sf::RenderWindow* w) override;

	std::string getString() { return text; };
};