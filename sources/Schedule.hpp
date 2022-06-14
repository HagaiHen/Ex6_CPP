#pragma once
#include "Leauge.hpp"
#include "Team.hpp"
#include "Game.hpp"


class Schedule {

    private:
        Leauge* leauge;
        int round;
        vector<Team*> curr_round;
    
    public:
        Schedule();
        Schedule(Leauge* leauge);
        void next_round();
        ~Schedule();

};