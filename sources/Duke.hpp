#include<iostream>
#include<string.h>
#include"Player.hpp"
using namespace std;


namespace coup{

    class Duke:public Player{
        public:
            Duke(Game &game1,string name);
            void block(Player &p);
            void tax();
    };

}