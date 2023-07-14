#pragma once
#include "GuiElement.h"

class SimpleDrawable : public GuiElement // Class for only drawing simple things. No updating
{
	using GuiElement::GuiElement; // "Inherit" GuiElement constructors
public:
	virtual ~SimpleDrawable() = default;
	// Dear compiler, please auto-generate me copy & move constructors and operators
	SimpleDrawable(const SimpleDrawable&) = default;
	SimpleDrawable(SimpleDrawable&&) = default;
	SimpleDrawable& operator=(const SimpleDrawable&) = default;
	SimpleDrawable& operator=(SimpleDrawable&&) = default;

	// Public virtual functions
	virtual void update(float dt) override { ; };
	virtual void handleEvents(sf::Event& event) override { return; }
	virtual void render(sf::RenderWindow* w) override
	{
		w->draw(*this);
	};
};