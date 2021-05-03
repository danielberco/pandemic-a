#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <set>
#pragma once

namespace pandemic
{
class Player {

protected:
    string playerRole;
    string currentCity;
    Board board;
    City city;
public:

    Player() ;

    Player(Board b, City c): board(b), city(c){}

    Player& drive(City c);

    virtual Player& fly_direct(City c);

    Player& fly_charter(City c);

    Player& fly_shuttle(City c);

    virtual Player& build();

    virtual Player& discover_cure(Color c);
    
    virtual Player& treat(City city);

    string role();

    Player& take_card(City city);

};


}