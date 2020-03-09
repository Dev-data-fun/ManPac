#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <algorithm>


using namespace std;

class Node{

   const int INDEX;
   const int X;
   const int Y;
   bool CONSUMED;
   const int NT;
   bool SPECIAL;


   public:


   Node(const int& index, const int& x, const int& y, bool consumed, const int& nt):INDEX(index),X(x),Y(y),CONSUMED(consumed),NT(nt),SPECIAL(false){

   }

   Node(const int& index, const int& x, const int& y, const int& nt):INDEX(index),X(x),Y(y),CONSUMED(false), NT(nt), SPECIAL(false){


   }
   Node(const int& index, const int& x, const int& y, const int& nt, bool special):INDEX(index),X(x),Y(y),CONSUMED(false), NT(nt), SPECIAL(special){


   }

    bool getSpecial() {

        return SPECIAL;
    }

   int getx() {
       return X;
   }

   int gety() {
       return Y;
   }

   bool getconsumed() {
       return CONSUMED;
   }

   void setConsumed(bool eat) {

       CONSUMED = eat;

   }

   int getIndex() {

       return INDEX;
   }

   int getNT() {

       return NT;
   }


};

/*

class ManPac : public Node {

    int MOVEDIR;
    int ANIM;

public:

    ManPac();

};

*/
