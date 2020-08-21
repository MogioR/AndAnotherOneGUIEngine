#pragma once
#include <vector>
#include <map>
#include <functional>
#include "Gui.h"
#include "BasicButton.h"
#include "Slider.h"
#include "TextInput.h"
#include "Form.h"

class GuiManager
{
public:
	std::map<std::string, std::function<void(Gui *gui)>> commands;

	void createButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, Font& f, bool visible);
	void createButton(std::string id, std::string text, FloatRect r, std::string onClick, std::string onCover, Color backGround, Color textAndBorder, Font& f, bool visible);
	void createTextInput(std::string id, std::string tip, FloatRect r, std::string onCover, Font& f, bool visible);
	void createSlider(std::string id, float min, float max, float value, FloatRect rect, std::string onUpdate, bool visible);

	void update(float gameTime, Vector2i mouseV);
	void draw(RenderWindow& w);
	void inputEvent(Event e);
		
	GuiManager();

private:
	Form mainForm;

	bool isWriting;
	Gui* targetTextInput;
};



