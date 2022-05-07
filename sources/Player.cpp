#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{

        void Player::income(){
           
            
            if(this->player_coins >= MAX_COINS){
                throw std::runtime_error("Ambassador " + this->player_name + " have to coap now.");
            }
             this->player_game.can_do_turn(this->player_name);
             this->zero_flags();
            this->player_coins += 1;
            std::cout << "Income" << std::endl;
            this->player_game.do_turn();
        }

        void Player::foreign_aid(){
            
            
             if(this->player_coins >= MAX_COINS){
                throw std::runtime_error("Ambassador " + this->player_name + " have to coap now.");
            }
            this->player_game.can_do_turn(this->player_name);
            this->zero_flags();
            this->player_coins += 2;
            this->f_a_block = true;
            std::cout << "Foreign Aid" << std::endl;
            this->player_game.do_turn();
        }

        int  Player::coins() const{return this->player_coins;}

        std::string Player::name() const{return this->player_name;}

        bool Player::get_is_alive() const{return this->is_alive;}
        
        void Player::set_is_alive (bool is_alive_to_set){this->is_alive = is_alive_to_set;}

        void Player::coup(Player& player){
            std::cout<< this->player_name << "Coup" << player.name() << std::endl;
        }

        std::string Player::role() const{return this->player_type;}

        void Player::set_player_type(std::string player_type_to_set){this->player_type = std::move(player_type_to_set);}

        void Player::decrease_coins(int amount){
            this->player_coins -= amount;
        }

        void Player::increase_coins(int amount){
            this->player_coins += amount;
        }

        void Player::got_block_from_foreign_aid(){
            this->player_coins -= 2;
        }

        void Player::zero_flags(){
            this->f_a_block = false;
        }
};