
#ifndef DELAUNAY_DIVIDE_AND_CONQUER_UTILS_HPP
#define DELAUNAY_DIVIDE_AND_CONQUER_UTILS_HPP


#include <memory>
#include "../include/Point.hpp"
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>

bool compareByX(const std::shared_ptr<Point> &p1, const std::shared_ptr<Point> &p2);

bool compareByY(const std::shared_ptr<Point> &p1, const std::shared_ptr<Point> &p2);

std::vector<std::shared_ptr<Point>> InputPoints();
#endif //DELAUNAY_DIVIDE_AND_CONQUER_UTILS_HPP
