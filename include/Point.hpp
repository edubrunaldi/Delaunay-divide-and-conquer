#ifndef DELAUNAY_DIVIDE_AND_CONQUER_POINT_HPP
#define DELAUNAY_DIVIDE_AND_CONQUER_POINT_HPP

#include <cstddef>
#include <fstream>

class Point {
public:
  float x;
  float y;
  float angle;
  size_t index;

  Point() = default;

  bool operator==(const Point &rhs) const;
  bool operator!=(const Point &rhs) const;
};

#endif //DELAUNAY_DIVIDE_AND_CONQUER_POINT_HPP
