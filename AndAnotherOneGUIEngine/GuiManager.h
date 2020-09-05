#pragma once
#include <vector>
#include <map>
#include "Form.h"

class GuiManager
{
public:
	std::map<std::string, std::function<void(Gui *gui)>> commands;

	void update(float gameTime, Vector2i mouseV);
	void draw(RenderWindow& w);
	void inputEvent(Event e);
		
	GuiManager();


	Form mainForm;
private:
	bool isWriting;
	Gui* targetTextInput;
};



