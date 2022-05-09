#include <iostream>
#include <string.h>
#include "Duke.hpp"
using namespace coup;
using namespace std;

Duke::Duke(Game &game1, string name) : Player(game1, name)
{
    this->myRole = "Duke";
}

void Duke::block(Player &p)
{


    if (!p.dead)
    {
        if (p.last_move=="foreign_aid")
        {   this->coinsNum++; //for the shit tidy
        this->coinsNum--;
            p.coinsNum -= 2;
            return;
        }
    }
     throw runtime_error("cant block this move");
}

void Duke::tax()
{
    this->check_if_my_trun();

    this->coinsNum += 3;

    this->game->next_turn();
}