#include "Triangle.h"
#include <math.h>
int Triangle::numTri = 0;

Triangle::~Triangle() {
  numTri--;
  std::cout << "Triangle Destructor " << this->getColor() << "\n";
}

Triangle::Triangle(double s1, double s2, double s3, string color)
  :ColoredShape(color), side1(s1), side2(s2), side3(s3)
{
  numTri++;
}

double
Triangle::getArea(void) {
  double p=(side1+side2+side3)/2.;
  double area=sqrt(p*(p-side1)*(p-side2)*(p-side3));
  return area;
}

void 
Triangle::printArea(std::ostream &s) {
  s << "Triangle: color: " << this->getColor() << ", area: "
    << this->getArea()<< " numTri: " << numTri<< "\n";
}

