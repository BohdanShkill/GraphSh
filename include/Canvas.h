#pragma once
#include <vector>
#include <Color.h>

class Canvas{
private:
    int width_;
    int height_;
    std::vector<std::vector<Color>> pixels_; // 2D vector to store pixel data
public:
    Canvas();
    Canvas(int width, int height);

    int getWidth() const;
    int getHeight() const;

    void setWidth(int width);
    void setHeight(int height);

    void setPixel (int x, int y, const Color& color);
    Color getPixel (int x, int y) const;

    void drawLine (int x1, int y1, int x2, int y2, const Color& color);

    ~Canvas();
};