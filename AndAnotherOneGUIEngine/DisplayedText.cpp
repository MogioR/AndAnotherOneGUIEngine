#include "DisplayedText.h"

void DisplayedText::setPosition(float x, float y)
{
}

void DisplayedText::setSize(float left, float top)
{
}

void DisplayedText::setText(std::string text)
{
	this->text.setString(text);
}

void DisplayedText::update(float gameTime, Vector2i mouce)
{
}

void DisplayedText::draw(sf::RenderWindow& w)
{
	if(isVisible)
		w.draw(text);
}

DisplayedText::DisplayedText(std::string id, FloatRect rect, std::string text, Font &f, bool visible)
	: Gui(id,rect,visible), text(text,f) 
{
	this->text.setPosition(rect.left, rect.top);
}
