#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic
{

class Medic: public Player {
  public:
    Medic(Board board, City city):Player(board, city){}
    Player& treat(City c);
    const std::string role() const{
        return "Medic";
    }
 };
}