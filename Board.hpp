#include "City.hpp"
#include <iostream>
#include <map>
#include <string>
#include <set>
#pragma once

using namespace std;
namespace pandemic
{
class Board { 
  public:
  map<City,int> cube;
  set<City> station;
  bool city_cured[4] = {0};
  Board();
  int& operator[](City c);
  friend std::ostream& operator<<(std::ostream& output, const Board& board);
  bool is_clean();
};
  }