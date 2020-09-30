#pragma once
#include "Gui.h"
#include "BasicButton.h"
#include "Slider.h"
#include "TextInput.h"
#include "DisplayedText.h"
#include <functional>

struct Form : public Gui
{
	void setPosition(float x, float y);
	void setSize(float left, float top);

	void onEvent(Event e, std::map<std::string, std::function<void(Gui * gui)>> commands, bool& isWriting, Gui **targetTextInput);
	void draw(RenderWindow &w);
	void update(float gameTime, Vector2i mouse);
	void setVisible(bool a);

	void createButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, Font& f, bool visible);
	void createButton(std::string id, std::string text, FloatRect r, std::string onClick, std::string onCover, Color backGround, Color textAndBorder, Font& f, bool visible);
	void createTextInput(std::string id, std::string tip, FloatRect r, std::string onCover, Font& f, bool visible);
	void createSlider(std::string id, float min, float max, float value, FloatRect rect, std::string onUpdate, bool visible);
	void createDisplayText(std::string id, FloatRect rect, std::string text, Font& f, bool visible);
	void createForm(std::string id, FloatRect rect, bool visible);

	void createGuiByJson(std::string id, std::string in, Font& f);

	Form* getForm(std::string id);
	Gui* getGui(std::string id);

	std::vector<Gui*> gui;
	Form(std::string id, FloatRect rect, bool visible);
};

