#include<iostream>
#include<string.h>
#include"Captain.hpp"
using namespace coup;
using namespace std;

Captain::Captain(Game &game1,string name):Player(game1,name){
    this->myRole="Captain";
}
void Captain::steal(Player &p){
    this->check_if_my_trun();
    for (int i = 2; i >= 0; i--)
    {
        if(p.coinsNum>=i){
            this->last_move="steal"+to_string(i)+p.name;
            this->coinsNum+=i;
            p.coinsNum-=i;
            break;
        }
    }
    this->game->next_turn();
}

void Captain::block(Player &p){

    for (int i = 0; i <= 2; i++)
    {   const size_t n6=6;
        vector<string>players_name=this->game->players();
            //check if player p steal from someone
            if(p.last_move.substr(0,n6)=="steal"+to_string(i)){
                p.coinsNum-=i;
                //name of the player that p stole from
                string name=p.last_move.substr(n6);
                //search him and bring him back the coins
                for (size_t k = 0; k < this->game->playerList.size(); k++)
                {
                    if(this->game->playerList.at(k)->name==name&& !this->game->playerList.at(k)->dead){
                        this->game->playerList.at(k)->coinsNum+=i;
                    }
                    return;
                }
                
            }
    }

    throw runtime_error("cant block this move");
}
