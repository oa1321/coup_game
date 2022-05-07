
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Captain.hpp"
#include "Duke.hpp"
namespace coup{
        Captain::Captain(Game& game, std::string name): Player(game, std::move(name)){game.AddPlayer(*this);
        this->set_player_type("Captain");}
        void Captain::block(Captain& player){
            if (!player.get_is_alive()){
                throw std::runtime_error("Player is not alive");
            }
            std::cout << "Captain " << this->player_name << " blocked stealing " << player.name() << std::endl;
            player.got_blocked_stealing();
        }
        void Captain::block(Duke& player){
            if (!player.get_is_alive()){
                throw std::runtime_error("Player is not alive");
            }
            std::cout << "Captain " << this->player_name << " blocked stealing " << player.name() << std::endl;
            throw std::runtime_error("Captain can't block duke");
        }
        void Captain::got_blocked_stealing(){

            std::cout << "Captain " << this->player_name << " got blocked stealing " << std::endl;
            if(!this->can_be_blocked){
                std::cout << "Captain " << this->player_name << " can't be blocked." << std::endl;
            }
            can_be_blocked = false;
            //get last target from game and returns the money to him
            Player& target = this->player_game.get_player(last_target);
            target.increase_coins(2);
            this->decrease_coins(2);
            if(this->coins() < 0){
                this->player_coins = 0;
            }

        }
        void Captain::steal(Player& player){
            
             
            std::cout << "Captain " << this->player_name << " stole coins from " << player.name() << std::endl;
            if (this->player_coins >= MAX_COINS){
                throw std::runtime_error("Player needs to coap now.");
            }
            this->player_game.can_do_turn(this->player_name);
            this->zero_flags();
            if(player.coins() < 1){
                throw std::runtime_error("Player has no coins");
            }
            if(player.coins() < 2){
                this->increase_coins(1);
                player.decrease_coins(1);
                this->last_target = player.name();
            }
            else{
                this->increase_coins(2);
                player.decrease_coins(2);
                this->last_target = player.name();
            }
            this->player_game.do_turn();
        }

        void Captain::coup(Player& player){
            
           
            std::cout << "Captain " << this->player_name << " couped " << player.name() << std::endl;
            if(!player.get_is_alive()){
                throw std::runtime_error("Player is not alive");
            }
            if(this->player_coins < COUP_COST){
                throw std::runtime_error("Player has no coins");
            }
            this->player_game.can_do_turn(this->player_name);
             this->zero_flags();
            this->decrease_coins(COUP_COST);
            player.set_is_alive(false);
            this->player_game.do_turn();
        } 
        void Captain::zero_flags(){
            this->f_a_block = false;
            can_be_blocked = false;
        }
};