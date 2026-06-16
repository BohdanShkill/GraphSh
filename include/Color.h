#pragma once

class Color
{
private:
	int r;
	int g;
	int b;

public:
	Color();
	Color(int a, int b, int c);

	int getR() const;
	int getG() const;
	int getB() const;

	void setR(int value);
	void setG(int value);
	void setB(int value);

	void print() const;

	~Color();
};