#include<iostream>
#include<string.h>
#include"Player.hpp"
using namespace std;


namespace coup{

    class Contessa:public Player {

        public:
            Contessa(Game &game1,string name);
            void block(Player &p);
    };

}