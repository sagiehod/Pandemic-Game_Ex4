#include "Board.hpp"
namespace pandemic{
  bool Board::is_clean(){
    for(auto& p: diseas){
        if(p.second!=0){
          return false;
        }
    }
    return true;
  }
  int & Board::operator[](City city){
    return this->diseas[city];
  }
  void Board::remove_cures(){
    for(auto& p: diseas){
      p.second=0;
    }
  }
  ostream& operator<<(ostream& os,const Board& board){
    return os;
  }
// 
//
//   void Board::load(string name_file){
//     ifstream pr{name_file};
//
//     list<string> temp;
//     while (pr)
//     {
//       string s;
//       getline(pr, s);
//
//       string word = "";
//       for (auto c : s)
//       {
//           if (c == ' ')
//           {
//             // std::cout << word << '\n';
//                 temp.push_back(word);
//               word = "";
//           }
//           else {
//               word = word + c;
//           }
//       }
//       int counter=0;
// // cout << "/* message */" << '\n';
//       for (auto v : temp){
//         if(counter==0){
//           diseas[v]=0;
//         }
//         if(counter==1){
//           colors[]
//           string blue = Color::Blue
//         }
//         if(counter>1){
//
//         }
//        std::cout << v << "\n";
//        counte++;
//     }
//      std::cout << "/* message */" << '\n';
//      temp.clear();
// }
// }
}
