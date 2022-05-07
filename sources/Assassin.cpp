
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"

namespace coup{
        Assassin::Assassin(Game& game, std::string name): Player(game, std::move(name)){game.AddPlayer(*this);
        this->set_player_type("Assassin");}
        void Assassin::got_block(){
            
            if(!this->can_be_blocked){
                std::cout << "Assassin " << this->player_name << " can't be blocked." << std::endl;
                throw std::runtime_error("Assassin can't be blocked");
            }
            this->can_be_blocked = false;
            //get last target from game and revives it
            Player& target = this->player_game.get_player(last_target);
            target.set_is_alive(true);
        }
        void Assassin::coup(Player& player){
           
            
            std::cout << "Assassin " << this->player_name << " assined/coup " << player.name() << std::endl;
            if(!player.get_is_alive()){
                std::cout << "Assassin " << this->player_name << " assassinated " << player.name() << std::endl;
                throw std::runtime_error("Player is not alive");
            }
            if (this->player_coins < ASSASSIN_COUP_COST){
                throw std::runtime_error("Player has no coins");
            }
            this->player_game.can_do_turn(this->player_name);
            this->zero_flags();
            if(this->player_coins >= COUP_COST){
                this->decrease_coins(COUP_COST);
                player.set_is_alive(false);
                this->can_be_blocked = false;
            }
            else if(ASSASSIN_COUP_COST <= this->player_coins){
                this->decrease_coins(ASSASSIN_COUP_COST);
                player.set_is_alive(false);
                this->can_be_blocked = true;
                this->last_target = player.name();
            }
            this->player_game.do_turn();
        }
        void Assassin::zero_flags(){
            this->f_a_block = false;
            can_be_blocked = false;
        }

};