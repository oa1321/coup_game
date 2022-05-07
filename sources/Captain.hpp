#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
namespace coup{
    class Captain: public Player{
        private:
        const int MIN_COINS = 2;
            bool can_be_blocked = false;
            std::string last_target = "";
        public:
            Captain(Game& game, std::string name);
            void got_blocked_stealing();
            void block(Captain& player);
            void block(Duke& player);
            void steal(Player& player);
            void zero_flags() override; 
            void coup(Player& player) override;
    };
};