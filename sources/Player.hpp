#pragma once
#include<iostream>
#include<string.h>
#include"Game.hpp"
using namespace std;

namespace coup {
    class Game;
    class Player{

        public:
            string name;
            string myRole;
            int coinsNum;
            Game *game;
            string last_move;
            bool dead;

            Player(Game &game1,string &name);
            Player();
            void income();
            void foreign_aid();
            virtual void coup(Player &p);
            string role()const;
            int coins()const;
            
        protected:
            void check_if_my_trun()const;
    };

}