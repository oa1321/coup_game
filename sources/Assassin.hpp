#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Assassin: public coup::Player{
        private:
            const int ASSASSIN_COUP_COST = 3;
            std::string last_target = "";
            
        public :
            bool can_be_blocked = false;
            Assassin(coup::Game& game, std::string name);
            void got_block();
            void coup(coup::Player& player) override;
            void zero_flags() override;
    };
};