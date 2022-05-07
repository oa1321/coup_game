#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"

namespace coup{
        Ambassador::Ambassador(Game& game, std::string name): Player(game, std::move(name)){
            game.AddPlayer(*this);
            this->set_player_type("Ambassador");
        }
        void Ambassador::block(Captain& player){
            if (!player.get_is_alive()){
                throw std::runtime_error("Player is not alive");
            }
            std::cout << "Ambassador " << this->player_name << " blocks " << player.name() << " from stealing." << std::endl;
            player.got_blocked_stealing();
        }
        void Ambassador::transfer(Player& player, Player& target){
            
            if(this->player_coins >= MAX_COINS){
                throw std::runtime_error("Ambassador " + this->player_name + " have to coap now.");
            }
            std::cout << "Ambassador " << this->player_name << " transfers money from " << player.name() << " to " << target.name() << "." << std::endl;
            if(!player.get_is_alive()){
                throw std::runtime_error("Player is not alive");
            }
            if(!target.get_is_alive()){
                throw std::runtime_error("Target is not alive");
            }
            if(player.coins() < 1){
                throw std::runtime_error("Player has no coins");
            }
            this->player_game.can_do_turn(this->player_name);
            player.decrease_coins(1);
            target.increase_coins(1);
            this->player_game.do_turn();
        }

        void Ambassador::coup(Player& player){
            
            std::cout << "Ambassador " << this->player_name << " coup " << player.name() << "." << std::endl;
            if(!player.get_is_alive()){
                throw std::runtime_error("Player is not alive");
            }
            if(this->player_coins < COUP_COST){
                throw std::runtime_error("Player has no coins");
            }
            this->player_game.can_do_turn(this->player_name);
            this->decrease_coins(COUP_COST);
            player.set_is_alive(false);
            this->player_game.do_turn();
        }
        

};