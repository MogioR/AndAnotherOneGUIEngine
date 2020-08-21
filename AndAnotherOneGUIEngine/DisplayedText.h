#pragma once
#include "Gui.h"
class DisplayedText : public Gui
{
public:
	void setPosition(float x, float y);
	void setSize(float left, float top);

	void update(float gameTime, Vector2i mouce);
	void draw(sf::RenderWindow& w);

private:
	Text text;
};

