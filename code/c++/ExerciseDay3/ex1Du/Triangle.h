#ifndef _TRIANGLE
#define _TRIANGLE

#include "ColoredShape.h"

class Triangle: public ColoredShape {
 public:
  Triangle(double s1, double s2, double s3, string color);
  ~Triangle();
  double getArea(void);
  void printArea(std::ostream &s);  

 protected:

 private:
  double side1, side2, side3;
  static int numTri;
};

#endif // _TRIANGLE

  
