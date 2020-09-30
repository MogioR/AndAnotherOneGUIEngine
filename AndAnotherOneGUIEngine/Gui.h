#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"

using namespace sf;

class Gui
{
public:
	bool isVisible();

	Gui(std::string id, FloatRect rect,  bool visible);
	Vector2f getSize();
	Vector2f getPosition();
	std::string getId();
	FloatRect getRect();
	virtual void setPosition(float x, float y) = 0;
	virtual void setSize(float left, float top) = 0;
	virtual void setVisible(bool a);

	//json to_json() {};
protected:
	FloatRect rect;
	bool visible;
private:
	std::string id;
};

struct DrawableGui
{
	virtual void update(float gameTime, Vector2i mouce) = 0;
	virtual void draw(sf::RenderWindow& w) = 0;
};

struct ClicableGui
{
	bool clicked;
	std::string onClick;
	ClicableGui(std::string onClick);
};

struct CoverableGui
{
	bool covered;
	std::string onCover;
	CoverableGui(std::string onCover);
};

struct WritableGui
{
	bool writed;
	WritableGui();
	std::string inputData;
	virtual void tryInput(char c) = 0;
	virtual void tryDelite() = 0;
};