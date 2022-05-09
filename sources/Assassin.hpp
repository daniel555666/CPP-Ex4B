#include<iostream>
#include<string.h>
#include"Player.hpp"
using namespace std;


namespace coup{

    class Assassin:public Player {

        public:
            Assassin(Game &game1,string name);
            void coup(Player &p)override;
    };

}