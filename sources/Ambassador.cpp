#include <iostream>
#include <string.h>
#include "Ambassador.hpp"
using namespace coup;
using namespace std;

Ambassador::Ambassador(Game &game1, string name) : Player(game1, name)
{
    this->myRole = "Ambassador";
}
void Ambassador::block(Player &p)
{

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
                        return;
                    }
                }
                
            }
    }

    throw runtime_error("cant block this move");
}
void Ambassador::transfer(Player &p1, Player &p2)
{
    this->check_if_my_trun();
    this->last_move="transfer";

    if(p1.coinsNum>0){
        p1.coinsNum--;
        p2.coinsNum++;
    }
    else{
        throw runtime_error(" ERROR,the player have 0 coins");
    }
    this->game->next_turn();

}
