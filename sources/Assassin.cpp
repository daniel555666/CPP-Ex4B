#include <iostream>
#include <string.h>
#include "Assassin.hpp"
#include<vector>
using namespace coup;
using namespace std;

Assassin::Assassin(Game &game1, string name) : Player(game1, name)
{
    this->myRole = "Assassin";
}
void Assassin::coup(Player &p)
{   const size_t n6=6;
const size_t n7=7;
   if (game->playerList.at(game->turn_num)->name!=this->name||
        this->game->playerList.size()<2||this->game->playerList.size()>n6)
    {   
        throw runtime_error("ERROR ,cant play");
    }

    if (this->coinsNum < 3 || p.dead)
    {
        throw runtime_error("not enough coins");
    }

        p.dead=true;
        this->game->num_of_players--;

        if (this->coinsNum > n7)
        {
            this->coinsNum -= n7;
            this->last_move = "coup";
        }
        else
        {
            this->coinsNum -= 3;
            this->last_move = "coup" + p.name;
        }
    this->game->next_turn();
}
