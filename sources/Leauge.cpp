#include "Leauge.hpp"


vector<Team*> rnd_list = {
        new Team("t1", 0.32),
        new Team("t2", 0.45),
        new Team("t3", 0.42),
        new Team("t4", 0.64),
        new Team("t5", 0.72),
        new Team("t6", 0.15),
        new Team("t7", 0.63),
        new Team("t8", 0.54),
        new Team("t9", 0.26),
        new Team("t10", 0.74),
        new Team("t11", 0.82),
        new Team("t12", 0.65),
        new Team("t13", 0.17),
        new Team("t14", 0.57),
        new Team("t15", 0.43),
        new Team("t16", 0.29),
        new Team("t17", 0.46),
        new Team("t18", 0.21),
        new Team("t19", 0.85),
        new Team("t20", 0.75),
    };

Leauge::Leauge::Leauge() {
    for (size_t i = 0; i < 20; i++) {
        this->teams_list.push_back(rnd_list[i]);
    }
}

Leauge::Leauge::Leauge(vector<Team*> teams_list) {
    if (teams_list.size() <= 20) { 
        for (size_t i = 0; i < this->teams_list.size(); i++) {
            this->teams_list[i] = teams_list[i];
        }
    } else {
        for (size_t i = teams_list.size()-1; i < 20; i++) {
            this->teams_list.push_back(rnd_list[i]);
        }
    }
}

bool Leauge::contains(Team* t) {
    for (size_t i =0; i < this->teams_list.size(); i++) {
        if (t->get_name() == this->teams_list[i]->get_name()) {
            return true;
        }
    }
    return false;
}