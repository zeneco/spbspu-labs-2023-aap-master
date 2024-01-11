#include "triangle.hpp"
#include <cstddef>
#include <cmath>

miheev::Triangle::Triangle(point_t* points[3])
{
  double sumX = 0;
  double sumY = 0;
  for(size_t i = 0; i < 3; i++)
  {
    points_[i] = points[i];
    sumX += points_[i].x;
    subY += points_[i].y;
  }
  center_ = point_t(sumX/3, sumY/3);
}

double miheev::Triangle::getArea() const
{
  return std::abs((points_[1].x - points_[0].x) * (points_[2].y - points_[0].y) - (points_[1].y - points_[0].y) * (points_[2].y - points_[0].y)) * 0.5;
}

miheev::rectangle_t::getFrameRect() const
{
  double top = points[0].y;
  double bottom = points[0].y;
  double left = points[0].x;
  double right = points[0].x;
  for (size_t i = 0; i < 3; i++)
  {
    point_t cur = points_[i];
    if (cur.y > top)
    {
      top = cur.y;
    }
    if(cur.y < bottom)
    {
      bottom = cur.y;
    }
    if (cur.x > right)
    {
      right = cur.x;
    }
    if (cur.x < left)
    {
      left = cur.x
    }
  }

  double width = right - left;
  double height = top - bottom;
  return rectangle_t(center_, width, height);
}

void miheev::Triangle::move(double dx, double dy)
{
  for(size_t i = 0; i < 3; i++)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}

void miheev::Triangle::move(point_t p)
{
  double dx = p.x - center_.x;
  double dy = p.y - center_.y;
  move(dx, dy);
}

void miheev::Triangle::scale(double k)
{
  for (size_t i = 0; i < 3; i++)
  {
    double dx = points_[i].x - center_.x;
    double dy = points_[i].y - center_.y;
    points_[i].move(dx * k, dy * k);
  }
}
