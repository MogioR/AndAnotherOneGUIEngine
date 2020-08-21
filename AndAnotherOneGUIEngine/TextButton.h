#pragma once
#include "Button.h"

class TextButton : public Button
{
public:
	void setTextString(std::string);
	void setTextColor(Color color);

	TextButton(std::string text, Font& font, FloatRect r, std::string onClick, std::string onCover);

protected:
	Text text;
	void correctSizeText();
private:

};

