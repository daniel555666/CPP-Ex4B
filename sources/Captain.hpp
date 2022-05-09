#include<iostream>
#include<string.h>
#include"Player.hpp"
using namespace std;


namespace coup{

    class Captain:public Player {

        public:
            Captain(Game &game1,string name);
            void steal(Player &p);
            void block(Player &p);
    };

}