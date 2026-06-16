#include <iostream>
#include <Color.h>
#include <Canvas.h>

int main()
{
	Color whiet(255, 255, 255);
	Color orange(45, 56, 145);
	Canvas mousePaint(10, 10);
	mousePaint.setPixel(9, 9, orange);
	return 0;
} 