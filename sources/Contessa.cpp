#include<iostream>
#include<string.h>
#include"Contessa.hpp"
using namespace coup;
using namespace std;

Contessa::Contessa(Game &game1,string name):Player(game1,name){
    this->myRole="Contessa";
}
void Contessa::block(Player &p){

    vector<Player*> players_list=this->game->playerList;
           
        //check if player p did coup
        if(p.last_move.substr(0,4)=="coup"){
            // check if this player dead
              
            string name_of_dead=p.last_move.substr(4);
            for (size_t j = 0; j < this->game->playerList.size(); j++)
            {
               if( this->game->playerList.at(j)->name==name_of_dead&&this->game->playerList.at(j)->dead){
                   this->game->playerList.at(j)->dead=false;
                    this->game->num_of_players++;
                    return;
               }
            }
        }
        
    
    throw runtime_error(" ERROR in block");

    }