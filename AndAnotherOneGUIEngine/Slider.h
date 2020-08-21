#pragma once
#include "Gui.h"

class Slider : public Gui, public DrawableGui, public ClicableGui, public CoverableGui
{
public:
	void setState(float s);
	float getState();

	virtual void setStep() = 0;
	float getStep();

	virtual void setValue() = 0;
	float getValue();

	float getMax();
	virtual void setMax() = 0;

	float getMin();
	virtual void setMin() = 0;

	void calculateState(float value);
	float calculateValue();
	bool updated;

	Slider(std::string id, float min, float max, float value, FloatRect rect, std::string onUpdate, bool visible);

protected:
	float state;
	float step;
	float min;
	float max;
};

class BasicSlider : public Slider
{
public:
	void update(float gameTime, Vector2i mouce);
	void draw(sf::RenderWindow& w);

	void setPosition(float x, float y);
	void setSize(float left, float top);

	void setStep();
	void setValue();
	void setMax();
	void setMin();

	BasicSlider(std::string id, float min, float max, float value, FloatRect rect, std::string onUpdate, bool visible);
private:
	RectangleShape line;
	RectangleShape slider;
};