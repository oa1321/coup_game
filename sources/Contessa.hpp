#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
namespace coup{
    class Contessa: public Player{
        public:
            Contessa(Game& game, std::string name);
            void block(Assassin& player);
            void coup(Player& player) override;
    };
};