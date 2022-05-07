#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Captain.hpp"
#include "Player.hpp"
namespace coup{
    class Ambassador: public Player{
        public:
            Ambassador(Game& game, std::string name);
            void block(Captain& player);
            void transfer(Player& player, Player& target);

            void coup(Player& player) override;

    };
};