#include <iostream>
#include <string.h>
#include "Player.hpp"
#include <exception>
using namespace coup;
using namespace std;

void Player::check_if_my_trun() const
{ const size_t n6=6;
const size_t n10=10;
    if (game->playerList.at(game->turn_num)->name != name||
        this->game->playerList.size()<2||this->game->playerList.size()>n6
           ||this->coinsNum>n10)
    {
        throw runtime_error("ERROR ,cant play");
    }
}

Player::Player(Game &game1, string &name)
{   
    const size_t n6=6;
    if(game1.num_of_players==n6||game1.start){
        throw runtime_error("to much players,or alredy start the game");
    }
    this->name = name;
    this->dead = false;
    this->coinsNum = 0;
    this->game = &game1;
    this->game->num_of_players++;
    this->game->playerList.push_back(this); // need to check if no have the same name,for tests as well
}

void Player::income()
{
    this->check_if_my_trun();

    this->last_move = "income";
    this->coinsNum++;

    this->game->next_turn();
}

void Player::foreign_aid()
{
    this->check_if_my_trun();

    this->coinsNum += 2;
    this->last_move = "foreign_aid";

    this->game->next_turn();
}
void Player::coup(Player &p)
{      const size_t n6=6;
const size_t n7=7;
    if (game->playerList.at(game->turn_num)->name != name||
        this->game->playerList.size()<2||this->game->playerList.size()>n6)
    {  
        throw runtime_error("ERROR ,cant play");
    }

    if (this->coinsNum < n7||p.dead)
    {   
        throw runtime_error("not enough coins or player dead");
    }
    this->coinsNum -= n7;

    this->last_move = "coup";
    p.dead = true;
    this->game->num_of_players--;
    this->game->next_turn();
}

string Player::role()const
{
    return this->myRole;
}
int Player::coins()const
{
    return this->coinsNum;
}