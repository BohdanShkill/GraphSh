#include <Canvas.h>
#include <Color.h>
#include <iostream>


Canvas::Canvas(int width, int height) : width_(width), height_(height){
    pixels_.resize(height, std::vector<Color>(width, Color(255, 255, 255)));
} 


int Canvas::getHeight() const
{
    return height_;
}

int Canvas::getWidth() const
{
    return width_;
}

void Canvas::setPixel(int x, int y, const Color& color)
{
   if(x >= width_ || y >= height_ || x < 0 || y < 0){
    std::cout << "Your coordinates are invalid." << std::endl;
    return;
   }
   pixels_[y][x] = color;
}

Color Canvas::getPixel(int x, int y) const
{
   if(x >= width_ || y >= height_ || x < 0 || y < 0){
    std::cout << "Your coordinates are invalid." <<std::endl;
   }
   return pixels_[y][x];
}

Canvas::~Canvas(){
    std::cout<< "Canvas is die " << width_ << "x" << height_ << std::endl;
}