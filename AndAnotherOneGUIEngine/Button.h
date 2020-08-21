#pragma once
#include "Gui.h"

class Button : public Gui
{
public:
	Button(std::string text, Font& font, FloatRect r, std::string onClick, std::string onCover);
	
	bool press;
private:

};


 