#ifndef GUI_MANAGER_CPP
#define GUI_MANAGER_CPP
#include "GuiManager.h"
#include <iostream>
using namespace std;

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