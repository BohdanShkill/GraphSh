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

void Canvas::setWidth(int width){
    width_ = width;
}

void Canvas::setHeight(int height){
    height_ = height;
}

void Canvas::setPixel(int x, int y, const Color& color)
{
   if(x >= width_ || y >= height_ || x < 0 || y < 0){
    std::cout << "Your coordinates are invalid." << std::endl;
    return;
   }
   pixels_[y][x] = color;
}

void Canvas::drawLine(int x1, int x2, int y1, int y2, const Color& color){
   int dx = std::abs(x2 - x1);
   int dy = -std::abs(y2 - y1);
   int sx = (x1 < x2) ? 1 : -1;
   int sy = (y1 < y2) ? 1 : -1;
   int err = dx + dy;

   while(true){
    setPixel(x1, y1, color);
    if(x1 == x2 && y1 == y2) break;
    int e2 = 2 * err;
    if(e2 >= dy){ 
        err += dy;
        x1 += sx;
    }
    if(e2 <= dx){
        err += dx;
        y1 += sy;
    }   
    }
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