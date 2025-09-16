#pragma once
class Color
{
private:
	int r;
	int g;
	int b;

public:
	Color::Color();
	Color::Color(int a, int b, int c);

	int getR();
	int getG();
	int getB();

	void setR(int value);
	void setG(int value);
	void setB(int value);

	void print();

	~Color();
};