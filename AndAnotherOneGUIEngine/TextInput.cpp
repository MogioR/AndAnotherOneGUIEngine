#include "TextInput.h"
#include <iostream>

void TextInput::setTextFillColor(sf::Color color)
{
	text.setFillColor(color);

}

TextInput::TextInput(std::string id, std::string tip, FloatRect rect, std::string onCover, Font &f, bool visible) :
	Gui(id, rect, visible), CoverableGui(onCover)
{
	this->text.setFont(f);
	this->tip.setFont(f);
	this->tip.setCharacterSize(100);
	this->text.setString("");
	this->tip.setString(tip);
	correctSizeText();
	text.setCharacterSize(this->tip.getCharacterSize());
	text.setPosition(this->tip.getPosition());
	text.setOrigin(this->tip.getOrigin());
}

void TextInput::correctSizeText()
{
	FloatRect textRect = this->tip.getLocalBounds();
	while ((textRect.height >= rect.height-10) && this->tip.getCharacterSize() > 2)
	{
		this->tip.setCharacterSize(this->tip.getCharacterSize() - 1);
		textRect = this->tip.getLocalBounds();
	}
	this->tip.setCharacterSize(this->tip.getCharacterSize() - 1);
	this->tip.setOrigin(0, textRect.top + textRect.height / 2.0f);
	this->tip.setPosition(sf::Vector2f(this->rect.left + 5, this->rect.top + rect.height / 2.0f));
}

void BasicTextInput::tryInput(char c)
{
	inputData += c;
	text.setString(inputData);
	std::cout << inputData << std::endl;
}

void BasicTextInput::tryDelite()
{
	if (!inputData.empty())
		inputData.pop_back();
	text.setString(inputData);
	std::cout << inputData << std::endl;
	std::cout << inputData.size() << std::endl;
}

void BasicTextInput::update(float gameTime, Vector2i mouce)
{

}

void BasicTextInput::draw(sf::RenderWindow& w)
{
	w.draw(shape);
	if (!inputData.empty() || input)
		w.draw(text);
	else
		w.draw(tip);
}

void BasicTextInput::setPosition(float x, float y)
{

}

void BasicTextInput::setSize(float left, float top)
{

}

void BasicTextInput::setOutlineColor(Color c)
{
	shape.setOutlineColor(c);
}

BasicTextInput::BasicTextInput(std::string id, std::string tip, FloatRect rect, std::string onCover, Font& f, bool visible) :
	input(0), TextInput(id, tip, rect, onCover, f, visible)
{
	shape.setPosition(rect.left, rect.top);
	shape.setSize(Vector2f(rect.width, rect.height));
	shape.setFillColor(sf::Color::White);
	shape.setOutlineColor(sf::Color::Black);
	this->text.setFillColor(sf::Color::Black);
	this->tip.setFillColor(sf::Color::Black);
	shape.setOutlineThickness(5);
}
