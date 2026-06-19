#include <iostream>
#include <Color.h>

	Color::Color() : r(0), g(0), b(0)
	{}
	Color::Color(int a, int cb, int c)
	{
		if (a <= 255 && a >= 0)
		{
			r = a;
		}
		else {
			if (a > 255) r = 255;
			else if (a < 0) {r = 0;}
		}

		if (cb <= 255 && cb >= 0)
		{
			g = cb;
		}
		else {
			if (cb > 255) g = 255;
			else if (cb < 0) {g = 0;}
		}

		if (c <= 255 && c >= 0)
		{
			b = c;
		}
		else {
			if (c > 255) b = 255;
			else if (c < 0) {b = 0;}
		}
	}

	int Color::getR() const
	{
		return r;
	}
	int Color::getG() const
	{
		return g;
	}
	int Color::getB() const
	{
		return b;
	}

	void Color::setR(int value)
	{
		if (value <= 255 && value >= 0)
		{
			r = value;
		}
		else {
			if (value > 255) r = 255;
			else if (value < 0) r = 0;
		}

	}
	void Color::setG(int value)
	{
		if (value <= 255 && value >= 0)
		{
			g = value;
		}
		else {
			if (value > 255) g = 255;
			else if (value < 0) g = 0;
		}
	}
	void Color::setB(int value)
	{
		if (value <= 255 && value >= 0)
		{
			b = value;
		}
		else {
			if (value > 255) b = 255;
			else if (value < 0) b = 0;
		}
	}

	void Color::print() const
	{
		std::cout << r << "\t" << g << "\t" << b << std::endl;
	}

	Color::~Color()
	{
	}