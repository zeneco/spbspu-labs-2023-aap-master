#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace khoroshkin
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t newPoint) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
  };
}
#endif
