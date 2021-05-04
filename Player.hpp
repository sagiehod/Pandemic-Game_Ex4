#pragma once
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic{
  class Player{
  private:
    Board b;
    City c;
    set<City> cards_play;
    string Role_;
  public:
    Player(Board board_ ,City city_,string role_):b(board_),c(city_),Role_(role_){}

    Player& take_card(City c);
    string role();
    Player& drive(City c);
    Player& fly_charter(City c);
    Player& fly_shuttle(City c);

    virtual Player& build();
    virtual Player& fly_direct(City c);
    virtual Player& discover_cure(Color c);
    virtual Player& treat(City c);
  };
}
