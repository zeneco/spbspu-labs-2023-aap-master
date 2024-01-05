#include "input_output.hpp"
#include <sstream>
#include "square.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
void seryj::writeAnswer(std::ostream& out, CompositeShape& cs)
{
  out.precision(2);
  std::vector<rectangle_t> rec_vec = cs.getFrameRect();
  double area = cs.getArea();
  out << area << " ";
  for (int i = 0; i < cs.shapes; i++)
  {
    out << rec_vec[i].pos.x - rec_vec[i].width / 2 << " ";
    out << rec_vec[i].pos.y - rec_vec[i].height / 2 << " ";
    out << rec_vec[i].pos.x + rec_vec[i].width / 2 << " ";
    out << rec_vec[i].pos.y + rec_vec[i].height / 2 << " ";
  }
  out << "\n";
}
std::vector<std::string> seryj::readText(std::istream& inp)
{
  std::vector<std::string> text;
  int scale_args = 0;
  bool is_after_scale = 0;
  while (scale_args < 3)
  {
    std::string line;
    std::getline(inp, line, '\n');
    std::stringstream ss(line);
    while (ss.good())
    {
      std::string word;
      std::getline(ss, word, ' ');
      scale_args += is_after_scale ? 1 : 0;
      if (word == "SCALE")
        is_after_scale = true;
      text.push_back(word);
    }
  }
  return text;
}
std::vector<Shape*> seryj::analyseText(std::vector<std::string> inp)
{
std::string shape_name;
Shape* ptr = nullptr;
std::vector<Shape*> v;
do
{
  if (ptr)
    v.push_back(ptr);
  shape_name = inp[0];
  if (shape_name == "SQUARE")
  try
  {
    ptr = new Square({ std::stod(inp[1]) ,std::stod(inp[2]) }, std::stod(inp[3]));
  }
  catch (std::exception const& e) { ptr = nullptr; }
  if (shape_name == "RECTANGLE")
   ptr = new Rectangle({ std::stod(inp[1]) , std::stod(inp[2]) }, { std::stod(inp[3]), std::stod(inp[4]) });
  if (shape_name == "REGULAR")
  {
    double arr[6];
    for (int i = 1; i <= 6; i++)
      arr[i - 1] = std::stod(inp[i]);
    ptr = new Regular({ arr[1], arr[2]}, {arr[3],arr[4]}, {arr[5],arr[6]});
  }
  if (shape_name != "SCALE")
    seryj::skipShape(inp);
} while (shape_name != "SCALE");
return v;
}
void seryj::skipShape(std::vector<std::string>& v)
{
  do
  {
    v.erase(v.begin(), v.begin() + 1);
  } while (v[0] != "SQUARE" && v[0] != "RECTANGLE" && v[0] != "REGULAR" && v[0] != "SCALE");
}
