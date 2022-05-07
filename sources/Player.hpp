#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"

namespace coup{
    class Game;
    class Player{
        protected:
            const int MAX_COINS = 10;
            const int COUP_COST = 7;
            Game& player_game;
            std::string player_name;
            int player_coins = 0;
            bool is_alive = true;
            std::string player_type;

        public:
            bool f_a_block = false;
            explicit Player(Game& game_to_set, std::string name_to_set): player_game(game_to_set), player_name(name_to_set){}
            void income();//done
            void foreign_aid();//done
            virtual void coup(Player& player);//done
            int coins () const;
            std::string name() const;//done

            bool get_is_alive() const;
            void set_is_alive(bool is_alive_to_set);
            std::string role() const;
            void set_player_type(std::string player_type_to_set);
            void decrease_coins(int amount);
            void increase_coins(int amount);
            void got_block_from_foreign_aid();
            virtual void zero_flags();
    };
};