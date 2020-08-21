#pragma once
#include "Gui.h"

class TextInput : public Gui, public DrawableGui, public WritableGui, public CoverableGui
{
public:
	void setTextFillColor(sf::Color color);
	TextInput(std::string id, std::string tip, FloatRect rect, std::string onCover, Font& f, bool visible);

protected:
	void correctSizeText();
	Text text;
	Text tip;
};

class BasicTextInput : public TextInput
{
public:
	void tryInput(char c);
	void tryDelite();
	
	void update(float gameTime, Vector2i mouce);
	void draw(sf::RenderWindow& w);

	void setPosition(float x, float y);
	void setSize(float left, float top);
	
	void setOutlineColor(Color c);

	bool input;
	BasicTextInput(std::string id, std::string tip, FloatRect rect, std::string onCover, Font& f, bool visible);

protected:
	RectangleShape shape;
};
