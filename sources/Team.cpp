#include "Team.hpp"
#include <iostream>

using namespace std;

Team::Team::Team() {
    this->name = "";
    this->skill_level = 0;
    this->final_score = 0;
}

Team::Team::Team(string n, double s_lvl) {
    if (s_lvl < 0 || s_lvl > 1) {
        throw invalid_argument("has to be between 0 - 1");
    }
    this->name = n;
    this->skill_level = s_lvl;
    this->final_score = 0;
}