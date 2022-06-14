#include "Schedule.hpp"
#include "Game.hpp"
#include <iostream>

Schedule::Schedule::Schedule() {
    this->leauge = new Leauge();
    this->round = 0;
}

Schedule::Schedule::Schedule(Leauge* leauge) {
    this->leauge = leauge;
    this->round = 0;
}

void Schedule::next_round() {
    if (this->round > 40) {
        throw invalid_argument("The season is over");
    }
    
    vector<Team*> home;
    vector<Team*> away;

    for (size_t i = 0; i < 10; i++) {
        home.push_back(this->leauge->get_teams_list()[i]);
    }
    for (size_t i = 19; i >= 10; i--) {
        away.push_back(this->leauge->get_teams_list()[i]);
    }


    for (size_t i =0; i < 10; i++) {
        Game g (home[i], away[i]);
        g.start_game();
    }

    this->round++;


}