#pragma once
#include "BasicButton.h"

void BasicButton::update(float gameTime, Vector2i mouce)
{
}

void BasicButton::draw(sf::RenderWindow &w)
{
	w.draw(shape);
	w.draw(text);
}

void BasicButton::setPosition(float x, float y)
{
	float _x = x - rect.left;
	float _y = y - rect.top;
	rect.left = x;
	rect.top = y;
	text.move(_x, _y);
	shape.move(_x, _y);
}

void BasicButton::setSize(float width, float height)
{
	rect.width = width;
	rect.height = height;
	
	shape.setSize(Vector2f(width, height));
	correctSizeText();
}

void BasicButton::setFillColor(Color color)
{
	shape.setFillColor(color);
}

json BasicButton::to_json()
{
	json j;
	j["type"] = "basic_button";
	j["id"] = getId();
	j["text_string"] = text.getString();
	j["text_color"] = text.getFillColor().toInteger();
	j["bg_color"] = shape.getFillColor().toInteger();
	j["rect_left"] = rect.left;
	j["rect_top"] = rect.top;
	j["rect_width"] = rect.width;
	j["rect_height"] = rect.height;
	j["on_click"] = onClick;
	j["on_cower"] = onCover;
	j["visible"] = visible;
	return j;
}

BasicButton::BasicButton(std::string id, std::string text, FloatRect rect, Font& f, bool visible = true) :
	Gui(id,rect, visible), ClicableGui("none"), CoverableGui("none")
{
	init(text,f);	
	shape.setFillColor(sf::Color::White);
	shape.setOutlineColor(sf::Color::Black);
	this->text.setFillColor(sf::Color::Black);
}

BasicButton::BasicButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, Font& f, bool visible = true) :
	Gui(id, rect, visible), ClicableGui(onClick), CoverableGui(onCover)
{
	init(text,f);
	shape.setFillColor(sf::Color::White);
	shape.setOutlineColor(sf::Color::Black);
	this->text.setFillColor(sf::Color::Black);
}

BasicButton::BasicButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, Color backGround, Color textAndBorder, Font& f, bool visible = true) :
	Gui(id, rect, visible), ClicableGui(onClick), CoverableGui(onCover)
{
	init(text, f);
	shape.setFillColor(backGround);
	shape.setOutlineColor(textAndBorder);
	this->text.setFillColor(textAndBorder);
}

BasicButton::BasicButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, int backGround, int textAndBorder, Font& f, bool visible) :
	BasicButton(id, text, rect, onClick, onCover, Color(backGround), Color(textAndBorder), f, visible) {};


void BasicButton::correctSizeText()
{
	FloatRect textRect = this->text.getLocalBounds();
	while ((textRect.width >= rect.width-10 || textRect.height >= rect.height) && this->text.getCharacterSize() > 2)
	{
		this->text.setCharacterSize(this->text.getCharacterSize() - 1);
		textRect = this->text.getLocalBounds();
	}
	this->text.setCharacterSize(this->text.getCharacterSize() - 1);

	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->text.setPosition(sf::Vector2f(this->rect.left + rect.width / 2.0f, this->rect.top + rect.height / 2.0f));
}

void BasicButton::init(std::string text, Font& f)
{
	shape.setPosition(rect.left, rect.top);
	shape.setSize(Vector2f(rect.width, rect.height));
	shape.setOutlineThickness(5);
	this->text.setString(text);
	this->text.setFont(f);
	this->text.setCharacterSize(100);
	correctSizeText();

}

