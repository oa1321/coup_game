
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"

namespace coup{
        Duke::Duke(Game& game, std::string name): Player(game, std::move(name)){game.AddPlayer(*this);
        this->set_player_type("Duke");}        
        void Duke::block(Player& player){
            if (!player.get_is_alive()){
                throw std::runtime_error("Player is not alive");
            }
            if(!player.f_a_block){
                throw std::runtime_error("Player can't be blocked");
            }
            std::cout << "Duke " << this->player_name << " blocks " << player.name() << " from foreign_aid." << std::endl;
            player.decrease_coins(2);
            if (player.coins() == -1){
                player.increase_coins(1);
            }
            else if (player.coins() == -2){
                player.increase_coins(2);
            }
        }
        void Duke::tax(){
            
            std::cout << "Duke " << this->player_name << " gets tax." << std::endl;
            if (this->player_coins >= MAX_COINS){
                throw std::runtime_error("Player needs to coap now.");
            }
            this->player_game.can_do_turn(this->player_name);
            this->increase_coins(3);
            this->player_game.do_turn();
        }
        void Duke::coup(Player& player) {
            
            std::cout << "Duke " << this->player_name << " coup " << player.name() << "." << std::endl;
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