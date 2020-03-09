#include "node.cpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <algorithm>




using namespace std;


class Maze{
    /*Maze class to represent the maze as a square matrix where each node within
     * the maze has neighbors to the left,right,up and down (if available) of itself.
     * Maze is a vector of Nodes stored in nodeVector.
     * Has private variables DIMENSIONS, representing row width of matrix
     * and COLLISION, representing whether the player and ghost have intersected.
     */

   vector<Node*>* nodeVector;       //Vector (of node pointers) pointer to store the nodes in the maze
   Node* ManPac;
   Node* RED;
   Node* BLUE;
   Node* PINK;
   Node* ORAN;


   public:

   Maze(){


      nodeVector = new vector<Node*>;

      nodeVector->push_back(new Node(0,27,27,0));
      nodeVector->push_back(new Node(1,47,27,9));
      nodeVector->push_back(new Node(2,67,27,9));
      nodeVector->push_back(new Node(3,87,27,9));
      nodeVector->push_back(new Node(4,107,27,9));
      nodeVector->push_back(new Node(5,127,27,4));
      nodeVector->push_back(new Node(6,147,27,9));
      nodeVector->push_back(new Node(7,167,27,9));
      nodeVector->push_back(new Node(8,187,27,9));
      nodeVector->push_back(new Node(9,207,27,9));
      nodeVector->push_back(new Node(10,227,27,9));
      nodeVector->push_back(new Node(11,247,27,1));
      nodeVector->push_back(new Node(12,307,27,0));
      nodeVector->push_back(new Node(13,327,27,9));
      nodeVector->push_back(new Node(14,347,27,9));
      nodeVector->push_back(new Node(15,367,27,9));
      nodeVector->push_back(new Node(16,387,27,9));
      nodeVector->push_back(new Node(17,407,27,9));
      nodeVector->push_back(new Node(18,427,27,4));
      nodeVector->push_back(new Node(19,447,27,9));
      nodeVector->push_back(new Node(20,467,27,9));
      nodeVector->push_back(new Node(21,487,27,9));
      nodeVector->push_back(new Node(22,507,27,9));
      nodeVector->push_back(new Node(23,527,27,1));
      nodeVector->push_back(new Node(24,27,47,8));
      nodeVector->push_back(new Node(25,127,47,8));
      nodeVector->push_back(new Node(26,247,47,8));
      nodeVector->push_back(new Node(27,307,47,8));
      nodeVector->push_back(new Node(28,427,47,8));
      nodeVector->push_back(new Node(29,527,47,8));
      nodeVector->push_back(new Node(30,27,67,8,true));
      nodeVector->push_back(new Node(31,127,67,8));
      nodeVector->push_back(new Node(32,247,67,8));
      nodeVector->push_back(new Node(33,307,67,8));
      nodeVector->push_back(new Node(34,427,67,8));
      nodeVector->push_back(new Node(35,527,67,8,true));
      nodeVector->push_back(new Node(36,27,87,8));
      nodeVector->push_back(new Node(37,127,87,8));
      nodeVector->push_back(new Node(38,247,87,8));
      nodeVector->push_back(new Node(39,307,87,8));
      nodeVector->push_back(new Node(40,427,87,8));
      nodeVector->push_back(new Node(41,527,87,8));
      nodeVector->push_back(new Node(42,27,107,7));
      nodeVector->push_back(new Node(43,47,107,9));
      nodeVector->push_back(new Node(44,67,107,9));
      nodeVector->push_back(new Node(45,87,107,9));
      nodeVector->push_back(new Node(46,107,107,9));
      nodeVector->push_back(new Node(47,127,107,10));
      nodeVector->push_back(new Node(48,147,107,9));
      nodeVector->push_back(new Node(49,167,107,9));
      nodeVector->push_back(new Node(50,187,107,4));
      nodeVector->push_back(new Node(51,207,107,9));
      nodeVector->push_back(new Node(52,227,107,9));
      nodeVector->push_back(new Node(53,247,107,5));
      nodeVector->push_back(new Node(54,267,107,9));
      nodeVector->push_back(new Node(55,287,107,9));
      nodeVector->push_back(new Node(56,307,107,5));
      nodeVector->push_back(new Node(57,327,107,9));
      nodeVector->push_back(new Node(58,347,107,9));
      nodeVector->push_back(new Node(59,367,107,4));
      nodeVector->push_back(new Node(60,387,107,9));
      nodeVector->push_back(new Node(61,407,107,9));
      nodeVector->push_back(new Node(62,427,107,10));
      nodeVector->push_back(new Node(63,447,107,9));
      nodeVector->push_back(new Node(64,467,107,9));
      nodeVector->push_back(new Node(65,487,107,9));
      nodeVector->push_back(new Node(66,507,107,9));
      nodeVector->push_back(new Node(67,527,107,6));
      nodeVector->push_back(new Node(68,27,127,8));
      nodeVector->push_back(new Node(69,127,127,8));
      nodeVector->push_back(new Node(70,187,127,8));
      nodeVector->push_back(new Node(71,367,127,8));
      nodeVector->push_back(new Node(72,427,127,8));
      nodeVector->push_back(new Node(73,527,127,8));
      nodeVector->push_back(new Node(74,27,147,8));
      nodeVector->push_back(new Node(75,127,147,8));
      nodeVector->push_back(new Node(76,187,147,8));
      nodeVector->push_back(new Node(77,367,147,8));
      nodeVector->push_back(new Node(78,427,147,8));
      nodeVector->push_back(new Node(79,527,147,8));
      nodeVector->push_back(new Node(80,27,167,2));
      nodeVector->push_back(new Node(81,47,167,9));
      nodeVector->push_back(new Node(82,67,167,9));
      nodeVector->push_back(new Node(83,87,167,9));
      nodeVector->push_back(new Node(84,107,167,9));
      nodeVector->push_back(new Node(85,127,167,6));
      nodeVector->push_back(new Node(86,187,167,2));
      nodeVector->push_back(new Node(87,207,167,9));
      nodeVector->push_back(new Node(88,227,167,9));
      nodeVector->push_back(new Node(89,247,167,1));
      nodeVector->push_back(new Node(90,307,167,0));
      nodeVector->push_back(new Node(91,327,167,9));
      nodeVector->push_back(new Node(92,347,167,9));
      nodeVector->push_back(new Node(93,367,167,3));
      nodeVector->push_back(new Node(94,427,167,7));
      nodeVector->push_back(new Node(95,447,167,9));
      nodeVector->push_back(new Node(96,467,167,9));
      nodeVector->push_back(new Node(97,487,167,9));
      nodeVector->push_back(new Node(98,507,167,9));
      nodeVector->push_back(new Node(99,527,167,3));

      nodeVector->push_back(new Node(100,127,187,8));
      nodeVector->push_back(new Node(101,247,187,true,8));
      nodeVector->push_back(new Node(102,307,187,true,8));
      nodeVector->push_back(new Node(103,427,187,8));


      nodeVector->push_back(new Node(104,127,207,8));
      nodeVector->push_back(new Node(105,247,207,true,8));
      nodeVector->push_back(new Node(106,307,207,true,8));
      nodeVector->push_back(new Node(107,427,207,8));

      nodeVector->push_back(new Node(108,127,227,8));
      nodeVector->push_back(new Node(109,187,227,true,0));
      nodeVector->push_back(new Node(110,207,227,true,9));
      nodeVector->push_back(new Node(111,227,227,true,9));
      nodeVector->push_back(new Node(112,247,227,true,5));
      nodeVector->push_back(new Node(113,267,227,true,9));
      nodeVector->push_back(new Node(114,287,227,true,9));
      nodeVector->push_back(new Node(115,307,227,true,5));
      nodeVector->push_back(new Node(116,327,227,true,9));
      nodeVector->push_back(new Node(117,347,227,true,9));
      nodeVector->push_back(new Node(118,367,227,true,1));
      nodeVector->push_back(new Node(119,427,227,8));



      nodeVector->push_back(new Node(120,127,247,8));
      nodeVector->push_back(new Node(121,187,247,true,8));
      nodeVector->push_back(new Node(122,367,247,true,8));
      nodeVector->push_back(new Node(123,427,247,8));

      nodeVector->push_back(new Node(124,127,267,8));
      nodeVector->push_back(new Node(125,187,267,true,8));
      nodeVector->push_back(new Node(126,367,267,true,8));
      nodeVector->push_back(new Node(127,427,267,8));


      nodeVector->push_back(new Node(128,7,287,true,9));
      nodeVector->push_back(new Node(129,27,287,true,9));
      nodeVector->push_back(new Node(130,47,287,true,9));
      nodeVector->push_back(new Node(131,67,287,true,9));
      nodeVector->push_back(new Node(132,87,287,true,9));
      nodeVector->push_back(new Node(133,107,287,true,9));
      nodeVector->push_back(new Node(134,127,287,10));
      nodeVector->push_back(new Node(135,147,287,true,9));
      nodeVector->push_back(new Node(136,167,287,true,9));
      nodeVector->push_back(new Node(137,187,287,true,6));
      nodeVector->push_back(new Node(138,367,287,true,7));
      nodeVector->push_back(new Node(139,387,287,true,9));
      nodeVector->push_back(new Node(140,407,287,true,9));
      nodeVector->push_back(new Node(141,427,287,10));
      nodeVector->push_back(new Node(142,447,287,true,9));
      nodeVector->push_back(new Node(143,467,287,true,9));
      nodeVector->push_back(new Node(144,487,287,true,9));
      nodeVector->push_back(new Node(145,507,287,true,9));
      nodeVector->push_back(new Node(146,527,287,true,9));
      nodeVector->push_back(new Node(147,547,287,true,9));



      nodeVector->push_back(new Node(148,127,307,8));
      nodeVector->push_back(new Node(149,187,307,true,8));
      nodeVector->push_back(new Node(150,367,307,true,8));
      nodeVector->push_back(new Node(151,427,307,8));


      nodeVector->push_back(new Node(152,127,327,8));
      nodeVector->push_back(new Node(153,187,327,true,8));
      nodeVector->push_back(new Node(154,367,327,true,8));
      nodeVector->push_back(new Node(155,427,327,8));



      nodeVector->push_back(new Node(156,127,347,8));
      nodeVector->push_back(new Node(157,187,347,true,7));
      nodeVector->push_back(new Node(158,207,347,true,9));
      nodeVector->push_back(new Node(159,227,347,true,9));
      nodeVector->push_back(new Node(160,247,347,true,9));
      nodeVector->push_back(new Node(161,267,347,true,9));
      nodeVector->push_back(new Node(162,287,347,true,9));
      nodeVector->push_back(new Node(163,307,347,true,9));
      nodeVector->push_back(new Node(164,327,347,true,9));
      nodeVector->push_back(new Node(165,347,347,true,9));
      nodeVector->push_back(new Node(166,367,347,true,6));
      nodeVector->push_back(new Node(167,427,347,8));




      nodeVector->push_back(new Node(168,127,367,8));
      nodeVector->push_back(new Node(169,187,367,true,8));
      nodeVector->push_back(new Node(170,367,367,true,8));
      nodeVector->push_back(new Node(171,427,367,8));


      nodeVector->push_back(new Node(172,127,387,8));
      nodeVector->push_back(new Node(173,187,387,true,8));
      nodeVector->push_back(new Node(174,367,387,true,8));
      nodeVector->push_back(new Node(175,427,387,8));


      nodeVector->push_back(new Node(176,27,407,0));
      nodeVector->push_back(new Node(177,47,407,9));
      nodeVector->push_back(new Node(178,67,407,9));
      nodeVector->push_back(new Node(179,87,407,9));
      nodeVector->push_back(new Node(180,107,407,9));
      nodeVector->push_back(new Node(181,127,407,10));
      nodeVector->push_back(new Node(182,147,407,9));
      nodeVector->push_back(new Node(183,167,407,9));
      nodeVector->push_back(new Node(184,187,407,5));
      nodeVector->push_back(new Node(185,207,407,9));
      nodeVector->push_back(new Node(186,227,407,9));
      nodeVector->push_back(new Node(187,247,407,1));
      nodeVector->push_back(new Node(188,307,407,0));
      nodeVector->push_back(new Node(189,327,407,9));
      nodeVector->push_back(new Node(190,347,407,9));
      nodeVector->push_back(new Node(191,367,407,5));
      nodeVector->push_back(new Node(192,387,407,9));
      nodeVector->push_back(new Node(193,407,407,9));
      nodeVector->push_back(new Node(194,427,407,10));
      nodeVector->push_back(new Node(195,447,407,9));
      nodeVector->push_back(new Node(196,467,407,9));
      nodeVector->push_back(new Node(197,487,407,9));
      nodeVector->push_back(new Node(198,507,407,9));
      nodeVector->push_back(new Node(199,527,407,1));


      nodeVector->push_back(new Node(200,27,427,8));
      nodeVector->push_back(new Node(201,127,427,8));
      nodeVector->push_back(new Node(202,247,427,8));
      nodeVector->push_back(new Node(203,307,427,8));
      nodeVector->push_back(new Node(204,427,427,8));
      nodeVector->push_back(new Node(205,527,427,8));

      nodeVector->push_back(new Node(206,27,447,8));
      nodeVector->push_back(new Node(207,127,447,8));
      nodeVector->push_back(new Node(208,247,447,8));
      nodeVector->push_back(new Node(209,307,447,8));
      nodeVector->push_back(new Node(210,427,447,8));
      nodeVector->push_back(new Node(211,527,447,8));

      nodeVector->push_back(new Node(212,27,467,2,true));
      nodeVector->push_back(new Node(213,47,467,9));
      nodeVector->push_back(new Node(214,67,467,1));
      nodeVector->push_back(new Node(215,127,467,7));
      nodeVector->push_back(new Node(216,147,467,9));
      nodeVector->push_back(new Node(217,167,467,9));
      nodeVector->push_back(new Node(218,187,467,4));
      nodeVector->push_back(new Node(219,207,467,9));
      nodeVector->push_back(new Node(220,227,467,9));
      nodeVector->push_back(new Node(221,247,467,5));
      nodeVector->push_back(new Node(222,267,467,9));
      nodeVector->push_back(new Node(223,287,467,9));
      nodeVector->push_back(new Node(224,307,467,5));
      nodeVector->push_back(new Node(225,327,467,9));
      nodeVector->push_back(new Node(226,347,467,9));
      nodeVector->push_back(new Node(227,367,467,4));
      nodeVector->push_back(new Node(228,387,467,9));
      nodeVector->push_back(new Node(229,407,467,9));
      nodeVector->push_back(new Node(230,427,467,6));
      nodeVector->push_back(new Node(231,487,467,0));
      nodeVector->push_back(new Node(232,507,467,9));
      nodeVector->push_back(new Node(233,527,467,3,true));

      nodeVector->push_back(new Node(234,67,487,8));
      nodeVector->push_back(new Node(235,127,487,8));
      nodeVector->push_back(new Node(236,187,487,8));
      nodeVector->push_back(new Node(237,367,487,8));
      nodeVector->push_back(new Node(238,427,487,8));
      nodeVector->push_back(new Node(239,487,487,8));

      nodeVector->push_back(new Node(240,67,507,8));
      nodeVector->push_back(new Node(241,127,507,8));
      nodeVector->push_back(new Node(242,187,507,8));
      nodeVector->push_back(new Node(243,367,507,8));
      nodeVector->push_back(new Node(244,427,507,8));
      nodeVector->push_back(new Node(245,487,507,8));

      nodeVector->push_back(new Node(246,27,527,0));
      nodeVector->push_back(new Node(247,47,527,9));
      nodeVector->push_back(new Node(248,67,527,5));
      nodeVector->push_back(new Node(249,87,527,9));
      nodeVector->push_back(new Node(250,107,527,9));
      nodeVector->push_back(new Node(251,127,527,3));
      nodeVector->push_back(new Node(252,187,527,2));
      nodeVector->push_back(new Node(253,207,527,9));
      nodeVector->push_back(new Node(254,227,527,9));
      nodeVector->push_back(new Node(255,247,527,1));
      nodeVector->push_back(new Node(256,307,527,0));
      nodeVector->push_back(new Node(257,327,527,9));
      nodeVector->push_back(new Node(258,347,527,9));
      nodeVector->push_back(new Node(259,367,527,3));
      nodeVector->push_back(new Node(260,427,527,2));
      nodeVector->push_back(new Node(261,447,527,9));
      nodeVector->push_back(new Node(262,467,527,9));
      nodeVector->push_back(new Node(263,487,527,5));
      nodeVector->push_back(new Node(264,507,527,9));
      nodeVector->push_back(new Node(265,527,527,1));

      nodeVector->push_back(new Node(266,27,547,8));
      nodeVector->push_back(new Node(267,247,547,8));
      nodeVector->push_back(new Node(268,307,547,8));
      nodeVector->push_back(new Node(269,527,547,8));

      nodeVector->push_back(new Node(270,27,567,8));
      nodeVector->push_back(new Node(271,247,567,8));
      nodeVector->push_back(new Node(272,307,567,8));
      nodeVector->push_back(new Node(273,527,567,8));

      nodeVector->push_back(new Node(274,27,587,2));
      nodeVector->push_back(new Node(275,47,587,9));
      nodeVector->push_back(new Node(276,67,587,9));
      nodeVector->push_back(new Node(277,87,587,9));
      nodeVector->push_back(new Node(278,107,587,9));
      nodeVector->push_back(new Node(279,127,587,9));
      nodeVector->push_back(new Node(280,147,587,9));
      nodeVector->push_back(new Node(281,167,587,9));
      nodeVector->push_back(new Node(282,187,587,9));
      nodeVector->push_back(new Node(283,207,587,9));
      nodeVector->push_back(new Node(284,227,587,9));
      nodeVector->push_back(new Node(285,247,587,5));
      nodeVector->push_back(new Node(286,267,587,9));
      nodeVector->push_back(new Node(287,287,587,9));
      nodeVector->push_back(new Node(288,307,587,5));
      nodeVector->push_back(new Node(289,327,587,9));
      nodeVector->push_back(new Node(290,347,587,9));
      nodeVector->push_back(new Node(291,367,587,9));
      nodeVector->push_back(new Node(292,387,587,9));
      nodeVector->push_back(new Node(293,407,587,9));
      nodeVector->push_back(new Node(294,427,587,9));
      nodeVector->push_back(new Node(295,447,587,9));
      nodeVector->push_back(new Node(296,467,587,9));
      nodeVector->push_back(new Node(297,487,587,9));
      nodeVector->push_back(new Node(298,507,587,9));
      nodeVector->push_back(new Node(299,527,587,3));


      ManPac = nodeVector->at(133);

      RED = nodeVector->at(113);
      BLUE = nodeVector->at(113);
      PINK = nodeVector->at(113);
      ORAN = nodeVector->at(113);

   }

/*
      int sz[244];        //Number of neighbours each node has (i.e node(0) has 2, node(1) has 3 etc.
      int nm[244][4];     //Neighbouring nodes of each node. (i.e nm[0][0] is node0's first neighbor).
      int dm[244][4];     //Direction of each respective neighbouring nodes a node has (as above).

*/

   void setMP (const int& index) {

       ManPac = nodeVector->at(index);

   }

   Node* getRED(){

       return RED;

   }


   void setRED (const int& index) {

       RED = nodeVector->at(index);

   }

   Node* getBLUE(){

       return BLUE;

   }


   void setBLUE (const int& index) {

       BLUE = nodeVector->at(index);

   }

   Node* getPINK(){

       return PINK;

   }


   void setPINK (const int& index) {

      PINK = nodeVector->at(index);

   }

   Node* getORAN(){

       return ORAN;

   }


   void setORAN (const int& index) {

      ORAN = nodeVector->at(index);

   }

   vector<Node*>* getNodes() {

       return nodeVector;
   }

   Node* getManPac(){

       return ManPac;

   }

   int find_node(int index, int inc) {

       //if(index<=150) {

           for(std::size_t i=0;i<this->nodeVector->size();i++) {

               if(((this->nodeVector->at(i)->getx()==this->nodeVector->at(index)->getx()) && this->nodeVector->at(i)->gety()==this->nodeVector->at(index)->gety()+inc)) {

                   return i;

               }

           }

    return 0;

   }

   ~Maze(){
      //De-constructor for Maze
      for(int i=0;i<300;i++){
         delete nodeVector->at(i);  //must delete each node
      }
      delete nodeVector;    //then deleted pointer to node vector
      delete ManPac;
      delete RED;
      delete BLUE;
      delete PINK;
      delete ORAN;
   }
};
