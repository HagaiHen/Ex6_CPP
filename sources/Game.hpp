#pragma once
#include "Team.hpp"

class Game {
    private:
        Team* home_team;
        Team* away_team;
        int home_score;
        int away_score;
        int status; // 0 - not start yet, 1 - playing, 2 - game over.
        int result; //0 - home won, 1 - away won.

    public:
        Game();
        Game(Team* h, Team* a);
        Game(const Game &game);
        void start_game();
        Team* get_home() {return this->home_team;};
        Team* get_away() {return this->away_team;};
        int get_home_score() {return this->home_score;};
        int get_away_score() {return this->away_score;};
        int get_status() {return this->status;};
        int get_result() {return this->result;};
        ~Game();
};