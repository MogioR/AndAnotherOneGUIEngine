#ifndef BASIC_BUTTON_H
#define BASIC_BUTTON_H
#include "Gui.h"
using nlohmann::json;

class BasicButton : public Gui, public DrawableGui, public ClicableGui, public CoverableGui
{
public:
	void update(float gameTime, Vector2i mouce);
	void draw(sf::RenderWindow &w);

	void setPosition(float x, float y);
	void setSize(float left, float top);
	
	void setFillColor(Color color);

	json to_json();
	void from_json();

	BasicButton(std::string id, std::string text, FloatRect rect, Font& f, bool visible);
	BasicButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, Font& f, bool visible);
	BasicButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, Color backGround, Color textAndBorder, Font& f, bool visible);
	BasicButton(std::string id, std::string text, FloatRect rect, std::string onClick, std::string onCover, int backGround, int textAndBorder, Font& f, bool visible);

protected:
	void correctSizeText();
	Text text;
	RectangleShape shape;

private:
	void init(std::string text, Font& f);
};
#endif

