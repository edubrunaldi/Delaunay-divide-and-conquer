
#include "../include/Point.hpp"
bool Point::operator==(const Point &rhs) const {
  return x==rhs.x && y==rhs.y;
}

bool Point::operator!= (const Point &rhs) const {
  return x!=rhs.x || y!=rhs.y;
}
