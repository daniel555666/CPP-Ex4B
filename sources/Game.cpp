#include <iostream>
#include <string.h>
#include "Game.hpp"

using namespace std;


namespace coup
{

    Game::Game()
    {
        this->turn_num = 0;
        this->num_of_players=0;
        this->start=false;
    }

    string Game::turn()
    {
        return playerList.at(turn_num)->name;
    }

    vector<string> Game::players()
    {
        vector<string> players_str;
        for (size_t i = 0; i < this->playerList.size(); i++)
        {   
            if(!this->playerList.at(i)->dead){
                players_str.push_back(this->playerList.at(i)->name);
            }
        }
        return players_str;
    }

    void Game::next_turn()
    {   
        this->start=true;
        for (size_t i = 0; i < this->playerList.size(); i++)
        {
            this->turn_num = (this->turn_num + 1) % (this->playerList.size());
            if (!this->playerList.at(this->turn_num)->dead)
            {
                break;
            }
        }
    }
    string Game::winner()
    {

        if (num_of_players == 1&& start)
        {
            for (size_t i = 0; i < this->playerList.size(); i++)
            {
                if(!this->playerList.at(i)->dead){
                    return this->playerList.at(i)->name;
                }
            }
            
        }
        throw runtime_error("the game is not over");
    }

}
