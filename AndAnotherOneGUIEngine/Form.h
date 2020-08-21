#pragma once
#include "Gui.h"
#include <functional>

struct Form : public Gui
{
	void setPosition(float x, float y);
	void setSize(float left, float top);

	void onEvent(Event e, std::map<std::string, std::function<void(Gui * gui)>> commands, bool& isWriting, Gui **targetTextInput);
	void draw(RenderWindow &w);
	void update(float gameTime, Vector2i mouse);

	std::vector<Gui*> gui;
	Form(std::string id, FloatRect rect, bool visible);
};

