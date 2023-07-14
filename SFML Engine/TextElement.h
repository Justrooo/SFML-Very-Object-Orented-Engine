#pragma once
#include "Object.h"

class TextElement : public sf::Text, private sf::Font, public virtual Object // Abstract class that represents text and font which can be updated and rendered
{
public:
	TextElement(const std::string font_path, const std::string text, sf::Vector2f pos)
	{
		loadFromFile(font_path);
		setFont(*this);
		setString(text);
		setPosition(pos);
	};
	explicit TextElement(const std::string font_path = "default_font.ttf", const std::string text = "Text", float x = 0.f, float y = 0.f) : TextElement{ font_path, text, {x, y} }
	{}
	virtual ~TextElement() = 0 {};

	// Dear compiler, please auto-generate me copy & move constructors and operators
	TextElement(const TextElement&) = default;
	TextElement(TextElement&&) = default;
	TextElement& operator=(const TextElement&) = default;
	TextElement& operator=(TextElement&&) = default;
};