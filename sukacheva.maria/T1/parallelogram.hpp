#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace sukacheva
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(point_t A, point_t B, point_t C);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double x, double y);
    void move(point_t center);
    void scale(double k);
    void newScale(point_t center, double k);
  private:
    point_t A_;
    point_t B_;
    point_t C_;
  };
}

#endif
