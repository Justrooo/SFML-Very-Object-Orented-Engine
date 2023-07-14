#pragma once
#include "Button.h"
#include "TextElement.h"

class TextButton : public TextElement, public Button // Button that is a text. Clickable and TextElement inherit virtually, so here we have one Object, not two
{
public:
	explicit TextButton(const std::string font_path = "default_font.ttf", const std::string text = "Text", float x = 0.f, float y = 0.f, std::function<void()> lambda = nullptr, double click_cooldown = 0.5, bool click_once = false)
		: TextElement{ font_path, text, x, y }, Button{ lambda, getGlobalBounds(), click_cooldown, click_once}
	{}
	TextButton(const std::string font_path, const std::string text, sf::Vector2f pos, std::function<void()> lambda, double click_cooldown, bool click_once)
		: TextButton{font_path, text, pos.x, pos.y, lambda, click_cooldown, click_once}
	{}
	virtual ~TextButton() = default;
	
	virtual void update(float dt) override;
	virtual void handleEvents(sf::Event& event) override { return; }
	virtual void render(sf::RenderWindow* w) override;
};