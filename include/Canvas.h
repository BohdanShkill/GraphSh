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

    void setPixel (int x, int y, const Color& color);
    Color getPixel (int x, int y) const;

    ~Canvas();
};