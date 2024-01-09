#include "funcs.hpp"
#include <iostream>
#include <cctype>
#include <set>

char * susidko::replaceUpLow(char * src, int add)
{
  char * res = new char[add];
  if (!res)
  {
    return nullptr;
  }
  int i = 0;
  while (src[i] != '\0')
  {
    res[i] = tolower(src[i]);
    if (!res)
    {
      return nullptr;
    }
    i++;
  }
  res[i] = '\0';
  return res;
}

int susidko::countDiffLetters(char * src)
{
  std::set<char> letters;
  for (int i = 0; src[i] != '\0'; i++)
  {
    if (isalpha(src[i]))
    {
      letters.insert(src[i]);
    }
  }
  return letters.size();
}
