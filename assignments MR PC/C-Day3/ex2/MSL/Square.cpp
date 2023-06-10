#include "Square.h"

int Square::numSquare = 0;

Square::~Square() {
  numSquare--;
  std::cout << "Square Destructor " << this->getColor() << "\n";
}

Square::Square(double w, double d, string color)
  :ColoredShape(color), width(w), height(d)
{
  numSquare++;
}

double
Square::getArea(void) {
  return width*width;
}

void 
Square::printArea(std::ostream &s) {
  s << "Square: color: " << this->getColor() << ", area: "
    << width * height << " numRect: " << numSquare << "\n";
}

