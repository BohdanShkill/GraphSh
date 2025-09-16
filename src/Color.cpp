#include <iostream>
#include <Color.h>

class Color
{
private:
	int r;
	int g;
	int b;

public:
	Color::Color()
	 : r(0), g(0), b(0);
	Color::Color(int a, int cb, int c)
	{
		if (a <= 255 && a >= 0)
		{
			r = a;
		}
		else {
			if (a > 255) r = 255;
			else (a < 0) r = 0;
		}

		if (cb <= 255 && cb >= 0)
		{
			g = cb;
		}
		else {
			if (cb > 255) g = 255;
			else (cb < 0) g = 0;
		}

		if (c <= 255 && c >= 0)
		{
			b = c;
		}
		else {
			if (c > 255) b = 255;
			else (c < 0) b = 0;
		}
	}

	int getR()
	{
		return r;
	}
	int getG()
	{
		return g;
	}
	int getB()
	{
		return b;
	}

	void setR(int value)
	{
		if (value <= 255 && value >= 0)
		{
			r = value;
		}
		else {
			if (value > 255) r = 255;
			else (value < 0) r = 0;
		}

	}
	void setG(int value)
	{
		if (value <= 255 && value >= 0)
		{
			g = value;
		}
		else {
			if (value > 255) g = 255;
			else (value < 0) g = 0;
		}
	}
	void setB(int value)
	{
		if (value <= 255 && value >= 0)
		{
			b = value;
		}
		else {
			if (value > 255) b = 255;
			else (value < 0) b = 0;
		}
	}

	void print()
	{
		std::cout << r << "\t" << g << "\t" << b << std::endl;
	}

	~Color()
	{
		std::cout << "Color is die" << r << "\t" << g << "\t" << b << std::endl;
	}
};