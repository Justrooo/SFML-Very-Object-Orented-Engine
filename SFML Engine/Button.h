#pragma once
#include "Clickable.h"

class Button : public Clickable // Abstact and better version of Clickable
{
protected:
	bool only_once; // if true once button is clicked, it will no longer respond to clicks
	bool clicked = false;

	void onClick(sf::RenderWindow* w);
public:
	Button(std::function<void()> lambda = nullptr, sf::FloatRect rect = sf::FloatRect(), double click_cooldown = 0.5, bool click_once = false) : Clickable{lambda, rect, click_cooldown }, only_once{ click_once } {};
	virtual ~Button() = 0 {};

	void resetClick() { clicked = false; };
};