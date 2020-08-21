#pragma once
#include "TextButton.h"

void TextButton::setTextString(std::string text)
{
	this->text.setString(text);
	correctSizeText();
}

void TextButton::setTextColor(Color color)
{
	text.setFillColor(color);
}

TextButton::TextButton(std::string text, Font& font, FloatRect rect, std::string onClick, std::string onCover) :
	text(text, font), Gui(rect, true, onClick, onCover, true) {}

void TextButton::correctSizeText()
{
	FloatRect textRect = this->text.getLocalBounds();
	while (textRect.width >= rect.width && textRect.height >= rect.height && this->text.getCharacterSize() > 1)
	{
		this->text.setCharacterSize(this->text.getCharacterSize() - 1);
		textRect = this->text.getLocalBounds();
	}

	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->text.setPosition(sf::Vector2f(this->rect.left + rect.width / 2.0f, this->rect.top + rect.height / 2.0f));
}
