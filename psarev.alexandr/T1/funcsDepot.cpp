#include "funcsDepot.hpp"
#include <cmath>

using namespace psarev;

bool psarev::rectDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue)
{
  double coo = 0.0;
  size_t iter = 0;
  bool result = false;
  for (size_t i = 0; i < 4; i++) {
    if (input >> coo) {
      data.push_back(coo);
      iter++;
    } else {
      result = true;
      break;
    }
  }
  if ((iter == 4) && (data[data.size() - 4] < data[data.size() - 2]) && (data[data.size() - 3] < data[data.size() - 1])) {
    queue.push_back('r');
  } else {
    for (size_t i = 0; i < iter; i++) {
      data.pop_back();
    }
    result = true;
  }
  return result;
}

bool psarev::ringDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue)
{
  double coo = 0.0;
  size_t iter = 0;
  bool result = false;
  for (size_t i = 0; i < 4; i++) {
    if (input >> coo) {
      data.push_back(coo);
      iter++;
    } else {
      result = true;
      break;
    }
  }
  if ((iter == 4) && (data[data.size() - 1] > 0) && (data[data.size() - 2] > data[data.size() - 1])) {
    queue.push_back('i');
  } else {
    for (size_t i = 0; i < iter; i++) {
      data.pop_back();
    }
    result = true;
  }
  return result;
}

bool psarev::triDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue)
{
  double coo = 0.0;
  size_t iter = 0;
  bool result = false;
  for (size_t i = 0; i < 6; i++) {
    if (input >> coo) {
      data.push_back(coo);
      iter++;
    }
    else {
      result = true;
      break;
    }
  }
  if (iter == 6) {
    double firEdge = (sqrt(pow(data[data.size() - 4] - data[data.size() - 6], 2) + pow(data[data.size() - 3] - data[data.size() - 5], 2)));
    double secEdge = (sqrt(pow(data[data.size() - 2] - data[data.size() - 4], 2) + pow(data[data.size() - 1] - data[data.size() - 3], 2)));
    double thirEdge = (sqrt(pow(data[data.size() - 2] - data[data.size() - 6], 2) + pow(data[data.size() - 1] - data[data.size() - 5], 2)));
    bool result = 0;
    result = (firEdge + secEdge > thirEdge) && (firEdge + thirEdge > secEdge) && (secEdge + secEdge > firEdge);
    if (result) {
      queue.push_back('t');
    } else {
      for (size_t i = 0; i < iter; i++) {
        data.pop_back();
      }
      result = true;
    }
  } else {
    for (size_t i = 0; i < iter; i++) {
      data.pop_back();
    }
    result = true;
  }
  return result;
}

void psarev::fillData(std::vector<double>& framesData, rectangle_t& frame, double& areaSum)
{
  areaSum += frame.width * frame.height;
  framesData.push_back(frame.pos.x - (frame.width / 2));
  framesData.push_back(frame.pos.y - (frame.height / 2));
  framesData.push_back(frame.pos.x + (frame.width / 2));
  framesData.push_back(frame.pos.y + (frame.height / 2));
}

void psarev::modify(point_t& scaleCenter, double& coef, Shape& figure, rectangle_t& frame)
{
  figure.move({ scaleCenter.x, scaleCenter.y });
  point_t newPos;
  newPos.x = fabs(frame.pos.x - scaleCenter.x) * coef;
  newPos.y = fabs(frame.pos.y - scaleCenter.y) * coef;
  figure.scale(coef);
  figure.move(newPos.x, newPos.y);
  frame = figure.getFrameRect();
}
