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
    CHECK_NOTHROW(player.take_card( City::Lima).fly_direct(City::Lima));
    CHECK_NOTHROW(player.build());
//Dispatcher
     CHECK_NOTHROW(player2.fly_direct(City::Paris));
     CHECK_NOTHROW(player2.take_card( City::Cairo).fly_direct(City::Cairo));

}

TEST_CASE("Test Scientist and Researcher"){
    
    Board board;
    Scientist player3(board, City::Washington, 4);
    Researcher player4(board, City::SaoPaulo);
//Scientist
    player3.take_card(City::Madrid);
    player3.take_card(City::Montreal);
    player3.take_card(City::SanFrancisco);
    player3.take_card(City::Chicago);
    player3.take_card(City::Washington);
    CHECK_NOTHROW(player3.build());
    CHECK_NOTHROW(player3.discover_cure(Blue));
    CHECK_THROWS(player3.fly_direct(City::Bangkok));
    CHECK_THROWS(player3.discover_cure(Color::Red));   
    //Researcher
    player4.take_card(City::SaoPaulo);
    player4.take_card(City::Miami);
    player4.take_card(City::LosAngeles);
    player4.take_card(City::Lima);
    player4.take_card(City::Chicago);
    player4.take_card(City::BuenosAires);
    CHECK_THROWS(player4.discover_cure(Color::Black));
    CHECK_NOTHROW(player4.discover_cure(Color::Yellow));
    CHECK_NOTHROW(player4.drive(City::Bogota));
    CHECK_THROWS(player4.discover_cure(Color::Yellow));
 
}

 TEST_CASE("Test Medic and Virologist"){

 Board board;
 	Medic player5(board, City::Moscow);
    Virologist player6(board, City::Jakarta);
    board[City::Moscow] = 5;
    board[City::StPetersburg] = 2;
    board[City::SanFrancisco] = 3;
    board[City::MexicoCity] = 4;

    //Medic
    CHECK_THROWS(player5.treat(City::Milan));
    CHECK_NOTHROW(player5.treat(City::Moscow));
    CHECK_EQ(board[City::Moscow], 0);
    CHECK_NOTHROW(player5.drive(City::StPetersburg));
    CHECK_NOTHROW(player5.treat(City::StPetersburg));
    CHECK_EQ(board[City::StPetersburg], 0);
   //Virologist
    player6.take_card(City::SanFrancisco);
    player6.take_card(City::MexicoCity);
    player6.take_card(City::Miami);
    CHECK_NOTHROW(player6.treat(City::SanFrancisco));
    CHECK_NOTHROW(player6.drive(City::Bangkok));
    CHECK_THROWS(player6.treat(City::Miami));
    CHECK_NOTHROW(player6.treat(City::MexicoCity));

 }

 TEST_CASE("Test GeneSplicer and FieldDoctor"){
     Board board;
 	GeneSplicer player7(board, City::Paris);
    FieldDoctor player8(board, City::Osaka);
    //GeneSplicer
    player7.take_card(City::Montreal);
    player7.take_card(City::Moscow);
    player7.take_card(City::Miami);
    player7.take_card(City::Bangkok);
    player7.take_card(City::Paris);
    player7.take_card(City::HongKong);

    CHECK_NOTHROW(player7.build());
    CHECK_NOTHROW(player7.discover_cure(Black));
    CHECK_THROWS(player7.discover_cure(Blue));

    //FieldDoctor
    board[City::Osaka] = 5;
    board[City::Tokyo] = 2;
    board[City::HongKong] = 1;
    board[City::Taipei] = 4;
    board[City::Santiago] = 5;

    CHECK_NOTHROW(player8.treat(City::Osaka));
    CHECK_NOTHROW(player8.treat(City::Tokyo));
    CHECK_EQ(board[City::Osaka], 4);
    CHECK_EQ(board[City::Tokyo], 1);
    CHECK_NOTHROW(player8.drive(City::Taipei));
    CHECK_NOTHROW(player8.treat(City::HongKong));
    CHECK_NOTHROW(player8.treat(City::Taipei));
    CHECK_THROWS(player8.treat(City::Santiago));
    CHECK_EQ(board[City::HongKong], 0);
    CHECK_EQ(board[City::Taipei], 3);

 }






