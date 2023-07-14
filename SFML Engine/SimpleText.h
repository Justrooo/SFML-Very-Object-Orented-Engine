#pragma once
#include "TextElement.h"

class SimpleText : public TextElement // A simple text which will be just rendered
{
	using TextElement::TextElement; // "Inherit" TextElement constructors
public:
	virtual ~SimpleText() = default;
	// Dear compiler, please auto-generate me copy & move constructors and operators
	SimpleText(const SimpleText&) = default;
	SimpleText(SimpleText&&) = default;
	SimpleText& operator=(const SimpleText&) = default;
	SimpleText& operator=(SimpleText&&) = default;

	// Public virtual functions
	virtual void update(float dt) override { return; };
	virtual void handleEvents(sf::Event& event) override { return; }
	virtual void render(sf::RenderWindow* w) override
	{
		w->draw(*this);
	};
};