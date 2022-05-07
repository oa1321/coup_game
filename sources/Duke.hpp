#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Duke: public Player{
        public:
            Duke(Game& game, std::string name);
            void block(Player& player);
            void tax();
            void coup(Player& player) override;
    };
};