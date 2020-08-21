#ifndef GUI_MANAGER_CPP
#define GUI_MANAGER_CPP
#include "GuiManager.h"
#include <iostream>
using namespace std;

void GuiManager::createButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, Font& f, bool visible = true)
{
	mainForm.gui.push_back(new BasicButton(id, text, rect, onClick, onCover, f, visible));
}

void GuiManager::createButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, Color backGround, Color textAndBorder, Font& f, bool visible = true)
{
	mainForm.gui.push_back(new BasicButton(id, text, rect, onClick, onCover, backGround, textAndBorder, f, visible));
}

void GuiManager::createTextInput(std::string id, std::string tip, FloatRect rect, std::string onCover, Font& f, bool visible)
{
	mainForm.gui.push_back(new BasicTextInput(id, tip, rect, onCover, f, visible));
}

void GuiManager::createSlider(std::string id, float min, float max, float value, FloatRect rect, std::string onUpdate, bool visible)
{
	mainForm.gui.push_back(new BasicSlider(id,min,max,value,rect,onUpdate,visible));
}

void GuiManager::update(float gameTime, Vector2i mouse)
{
	mainForm.update(gameTime, mouse);
}

void GuiManager::draw(RenderWindow& w)
{
	mainForm.draw(w);
}

void GuiManager::inputEvent(Event e)
{
	mainForm.onEvent(e, commands, isWriting, &targetTextInput);
}

GuiManager::GuiManager() :
	mainForm("MainForm", FloatRect(0,0,1920,1090), true) {}

#endif