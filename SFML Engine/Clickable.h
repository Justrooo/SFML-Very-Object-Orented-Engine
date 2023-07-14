#pragma once
#include "GuiElement.h"

class Clickable : public sf::FloatRect, public virtual Object // Abstact class which is something you can click. When you iherit from this class you need to set FloatRect::left, top, width and height !!!!!!!!!!
{
protected:
	double cooldown;
	std::function<void()> lambda;
	sf::Clock clock;

	bool onClick(sf::RenderWindow* w); // Check if clicking on Clickable. If so, call lambda (if lambda = nullptr dont call it)
	bool isClicking(); // Check only for click
	bool isHovering(sf::RenderWindow* w); // Check only for hovering
public:
	explicit Clickable(std::function<void()> lambda = nullptr, sf::FloatRect rect = sf::FloatRect(), double click_cooldown = 0.5) : sf::FloatRect{rect}, lambda{ lambda }, cooldown{ click_cooldown } {};
	virtual ~Clickable() = 0 {};
	// When Left click is detected, call lambda
};