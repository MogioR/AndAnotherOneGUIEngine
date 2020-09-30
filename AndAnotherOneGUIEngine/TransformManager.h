#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class TransformManager
{
	IntRect screen;
	double x1, x2, y1, y2;

	TransformManager(IntRect screen, double );

	Vector2i convert(double x, double y);

	double x(int X);
	double y(int Y);
};

