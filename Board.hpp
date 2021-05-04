#pragma once
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <list>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
  class Board{
    private:
      unordered_map<City,int> diseas;
      unordered_map<City,Color> colors;
      unordered_map<City,unordered_map<City,bool>> graph;


    public:
      // void load(string name_file);
      bool is_clean();
      void remove_cures();
      int & operator[](City city);
      friend ostream& operator<<(ostream& os,const Board& board);
  };
}
