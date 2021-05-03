#include "Board.hpp"
#include <map>
#include <iostream>
#include <string>

namespace pandemic
{

Board::Board() {
}

  int& Board::operator[](City city){
      return cube[city];
  }

  std::ostream& operator<<(std::ostream& output, const Board& board){
      return output << "Output Test";
  }

  bool Board::is_clean(){
      return true;
  }
}