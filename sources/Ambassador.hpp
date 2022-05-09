#include<iostream>
#include<string.h>
#include"Player.hpp"
using namespace std;


namespace coup{

    class Ambassador:public Player {

        public:
            Ambassador(Game &game1,string name);
            void block(Player &p);
            void transfer(Player &p1,Player &p2);
    };

}