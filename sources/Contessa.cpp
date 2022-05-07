
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Contessa.hpp"
#include "Assassin.hpp"
namespace coup{
        Contessa::Contessa(Game& game, std::string name): Player(game, std::move(name)){game.AddPlayer(*this);
        this->set_player_type("Contessa");}
        void Contessa::block(Assassin& player){
            if (!player.get_is_alive()){
                throw std::runtime_error("Player is not alive");
            }
            std::cout << "Contessa " << this->player_name << " blocked assassintion " << player.name() << std::endl;
            player.got_block();
        }
        void Contessa::coup(Player& player){
           
            std::cout << "Contessa " << this->player_name << " couped " << player.name() << std::endl;
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