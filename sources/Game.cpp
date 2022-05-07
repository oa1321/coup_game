#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include "Game.hpp"

namespace coup{
    Game::Game(): player_amount(0), turn_number(0), alivePlayers(0), currentPlayer(""){}
    void Game::AddPlayer(Player& player){
        if(player_amount == 0){
            currentPlayer = player.name();
        }
        if (turn_number > 0 ){
            throw std::runtime_error("Game already started");
        }
        if (player_amount >= MAX_PLAYERS){
            throw std::runtime_error("Max players reached");
        }
        //maybe throw when same name is given again 
        std::cout << "Adding player: " << player.name() << std::endl;
        players_list.push_back(&player);
        this->all_players.push_back(player.name());
        this->playerQueue.push(&player);
        this->player_amount++;
        this->alivePlayers++;
    }
    std::vector<std::string> Game::players(){
        //returns alive players
        std::vector<std::string> alive_players;
        for(auto& player : players_list){
            if(player->get_is_alive()){
                alive_players.push_back(player->name());
            }
        }
        return alive_players;
    }
    std::string Game::turn(){
        return this->currentPlayer;
    }

    std::string Game::do_turn(){

        if (this->player_amount < 2 && this->turn_number == 0){
            throw std::runtime_error("No players added");
        }
        this->turn_number++;
        Player* tplayer = this->playerQueue.front();
        this->playerQueue.pop();
        this->playerQueue.push(tplayer);
        while(!this->playerQueue.front()->get_is_alive()){
            Player* player = this->playerQueue.front();
            this->playerQueue.pop();
            this->playerQueue.push(player);
            
        }
        this->currentPlayer = this->playerQueue.front()->name();
        return this->currentPlayer;
    }
    std::string Game::winner(){
        std::cout << "Winner: " << this->currentPlayer << std::endl;
        std::string winner = this->currentPlayer;
        std::vector<std::string> alive_players;
        for(auto& player : players_list){
            if(player->get_is_alive()){
                alive_players.push_back(player->name());
            }
        }
        if(alive_players.size() == 1 && this->turn_number > 0){
            winner = alive_players[0];
        }
        else{
            throw std::runtime_error("Not finnshed yet");
        }
        return winner;
    }

    Player& Game::get_player(std::string& name){
        for(auto& player : this->players_list){
            if(player->name() == name){
                return *player;
            }
        }
        throw std::runtime_error("Player not found");
    }

    void Game::can_do_turn(std::string& name){
        
        if (this->player_amount < 2){
            throw std::runtime_error("No players added");
        }
        if (this->currentPlayer != name){
            std::cout << name << " is not the current "<< this->currentPlayer << std::endl;
            throw std::runtime_error("Not your turn");
        }
    }
};