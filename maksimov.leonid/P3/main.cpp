#include <iostream>
#include "comparison.hpp"
#include "delvow.hpp"
#include "newarr.hpp"

int main()
{
  size_t lenStr = 10;
  char* str = 0;
  try
  {
    str = newarr(std::cin, lenStr);
  }
  catch (const std::exception& ex)
  {
    std::cerr << "Could not read an element of the string\n";
    delete[] str;
    return 1;
  }
  std::cout << "[HAS-SAM]: " << arr::comparison(str, lenStr, "abc") << '\n';
  arr::delVow(str, lenStr);
  std::cout << "[RMV-VOW]: ";
  for (size_t i = 0; i < lenStr; i++)
  {
    std::cout << str[i];
  }
  delete[] str;
  return 0;
}
