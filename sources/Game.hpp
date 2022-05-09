#pragma once
#include<iostream>
#include<string.h>
#include<vector>
#include"Player.hpp" 
using namespace std;


namespace coup{
    
    class Player;

    class Game{

        public:
            size_t turn_num;
            vector<Player*>playerList;
            vector<string>last_move; 
            vector<Player*>dead_players;   
            int num_of_players;
            bool start;
            Game();
            string turn();
            vector<string>players();
            void next_turn();
            string winner();
            
        private:
             
   
    
             

       
    };

}