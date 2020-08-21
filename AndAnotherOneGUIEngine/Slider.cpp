#include "Slider.h"

void Slider::calculateState(float value)
{
	if (value <= min)
		state = 0;
	else if (value >= max)
		state = 100;
	else
		state = (value - min) / (max - min);
}

float Slider::calculateValue()
{
	return min+state * (max-min);
}

Slider::Slider(std::string id, float min, float max, float state, FloatRect rect, std::string onClick, bool visible)
	: Gui(id, rect, visible), ClicableGui(onClick), CoverableGui("none"), min(min), max(max), state(state), step(0), updated(0) {}

BasicSlider::BasicSlider(std::string id, float min, float max, float value, FloatRect rect, std::string onUpdate, bool visible) :
	Slider(id,min,max,value,rect,onUpdate,visible)
{
	calculateState(value);
	line.setPosition(rect.left, rect.top + rect.height / 2 - 2);
	line.setSize(Vector2f(rect.width, 4));

	slider.setOrigin(5, 0);
	slider.setSize(Vector2f(11, rect.height));
	slider.setPosition(rect.left+state*rect.width/100,rect.top);

	line.setFillColor(Color::Black);
	slider.setFillColor(Color::Black);
}

void Slider::setState(float s)
{
	state = s;
}

float Slider::getState()
{
	return state;
}

float Slider::getStep()
{
	return step;
}

float Slider::getValue()
{
	return calculateValue();
}

float Slider::getMax()
{
	return max;
}

float Slider::getMin()
{
	return min;
}

void BasicSlider::update(float gameTime, Vector2i mouse)
{
	if (clicked && covered)
	{
		setState((mouse.x - rect.left) / rect.width);
		slider.setPosition(mouse.x, rect.top);
		updated = 1;
	}
}

void BasicSlider::draw(sf::RenderWindow& w)
{
	w.draw(line);
	w.draw(slider);
}

void BasicSlider::setPosition(float x, float y)
{
}

void BasicSlider::setSize(float left, float top)
{
}

void BasicSlider::setStep()
{
}

void BasicSlider::setValue()
{
}

void BasicSlider::setMax()
{
}

void BasicSlider::setMin()
{
}
