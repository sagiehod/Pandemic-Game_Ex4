#include "doctest.h"
#include <iostream>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;
// drive ,build ,fly_direct,fly_charter,fly_shuttle,discover_cure,treat 
TEST_CASE("Test OperationsExpert and Dispatcher"){
//OperationsExpert
    Board board;
    OperationsExpert player {board, City::Atlanta};
    Dispatcher player2 {board, City::Lima};
    CHECK_NOTHROW(player.build());
    CHECK_THROWS(player.drive(City::Tokyo));
    CHECK_NOTHROW(player.drive(City::Chicago));
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.take_card( City::Chicago).take_card(City::Chicago));
    CHECK_NOTHROW(player.fly_direct(City::Lima));
    CHECK_NOTHROW(player.build());
//Dispatcher
     CHECK_NOTHROW(player2.fly_direct(City::Paris));
     CHECK_NOTHROW(player2.take_card( City::Cairo).fly_direct(City::Cairo));
   

}
TEST_CASE("Test Scientist and Researcher"){
    
    Board board;
    Scientist player3(board, City::Washington, 5);
    Researcher player4(board, City::Washington);
//Scientist
    CHECK_NOTHROW(player3.build());
    CHECK_NOTHROW(player3.discover_cure(Color::Blue));
    CHECK_NOTHROW(player3.build());
    CHECK_NOTHROW(player3.build());
    CHECK_THROWS(player3.fly_direct(City::Bangkok));
    CHECK_THROWS(player3.discover_cure(Color::Blue));   
    //Researcher
    CHECK_NOTHROW(player4.discover_cure(Color::Blue));
    CHECK_NOTHROW(player4.drive(City::Montreal));
    CHECK_NOTHROW(player4.discover_cure(Color::Blue));
    CHECK_NOTHROW(player4.fly_direct(City::Bangkok));
    player4.take_card( City::Washington);
    CHECK_NOTHROW(player4.discover_cure(Color::Blue));

}
// TEST_CASE("Test Medic and Researcher"){

// Board board;
// 	Medic player5(board, City::Moscow);
//     Researcher player4(board, City::Washington);



// }






