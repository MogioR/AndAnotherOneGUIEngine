#pragma once
#include "Gui.h"

bool Gui::isVisible()
{
	return visible;
}

Gui::Gui(std::string id, FloatRect rect, bool isVisible = true) :
	id(id), rect(rect), visible(isVisible) {}

Vector2f Gui::getSize()
{
	return Vector2f(rect.width, rect.height);
}

Vector2f Gui::getPosition()
{
	return Vector2f(rect.left, rect.top);
}

std::string Gui::getId()
{
	return id;
}

FloatRect Gui::getRect()
{
	return rect;
}
void Gui::setVisible(bool a)
{
	visible = a;
}

ClicableGui::ClicableGui(std::string onClick) :
	onClick(onClick), clicked(0) {}

CoverableGui::CoverableGui(std::string onCower) :
	onCover(onCower), covered(0) {}

WritableGui::WritableGui() :
	inputData(""), writed(0) {}
