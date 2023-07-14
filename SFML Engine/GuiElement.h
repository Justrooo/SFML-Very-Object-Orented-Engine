#pragma once
#include "Object.h"

class GuiElement : public sf::Sprite, private sf::Texture, public virtual Object // Abstract class to have a drawable element which is renderable and updatable
{
public:
	// Constructors
	explicit GuiElement(const std::string texture_path, sf::Vector2f pos)
	{
		loadFromFile(texture_path);
		setTexture(*this);
		setPosition(pos);
	};
	explicit GuiElement(const std::string texture_path = "missing.png", float x = 0.f, float y = 0.f) : GuiElement{texture_path, {x, y}}
	{}
	// Destructor
	virtual ~GuiElement() = 0 {};

	// Dear compiler, please auto-generate me copy & move constructors and operators
	GuiElement(const GuiElement&) = default;
	GuiElement(GuiElement&&) = default;
	GuiElement& operator=(const GuiElement&) = default;
	GuiElement& operator=(GuiElement&&) = default;
};