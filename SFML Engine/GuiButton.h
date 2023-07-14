#pragma once
#include "GuiElement.h"
#include "Button.h"

class GuiButton : public GuiElement, public Button // Button that is a sprite. Clickable and TextElement inherit virtually, so here we have one Object, not two
{
public:
	explicit GuiButton(const std::string texture_path = "missing.png", float x = 0.f, float y = 0.f, std::function<void()> lambda = nullptr, double click_cooldown = 0.5, bool click_once = false)
		: GuiElement{ texture_path, {x, y} }, Button{lambda, getGlobalBounds(), click_cooldown, click_once}
	{}
	GuiButton(const std::string texture_path, sf::Vector2f pos, std::function<void()> lambda, double click_cooldown, bool click_once)
		: GuiButton{ texture_path, pos.x, pos.y, lambda, click_cooldown, click_once }
	{}
	virtual ~GuiButton() = default;

	virtual void update(float dt) override { return; }
	virtual void handleEvents(sf::Event& event) override { return; }
	virtual void render(sf::RenderWindow* w) override;
};