#pragma once
#include "Team.hpp"
#include <vector>
using namespace std;

class Leauge {
    private:
        vector<Team*> teams_list;

    public:
        Leauge();
        Leauge(vector<Team*> teams_list);
        bool contains(Team* t);
        vector<Team*> get_teams_list() { return this->teams_list; };
        ~Leauge();
};