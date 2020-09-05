#pragma once
#include "Gui.h"
class DisplayedText : public Gui, public DrawableGui
{
public:
	void setPosition(float x, float y);
	void setSize(float left, float top);

	void setText(std::string text);
	void update(float gameTime, Vector2i mouce);
	void draw(sf::RenderWindow& w);

	DisplayedText(std::string id, FloatRect rect, std::string text, Font& f, bool visible);

private:
	Text text;
};