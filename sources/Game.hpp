#ifndef GAME_HPP
#define GAME_HPP
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include "Player.hpp"

namespace coup{
    const int MAX_PLAYERS = 6;
    class Player;
    class Game{
        private:
            std::vector<Player*> players_list;
            std::vector <std::string> all_players;
            std::string currentPlayer;
            int player_amount;
            int turn_number; // for debuging
            int alivePlayers;
            std::queue<Player*> playerQueue;
        public:

            Game();
            void AddPlayer(Player &player);
            std::vector<std::string> players();
            std::string turn();
            std::string winner();
            std::string do_turn();
            Player& get_player(std::string& name); 
            void can_do_turn(std::string& name);

    };
};
#endif