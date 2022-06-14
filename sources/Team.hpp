#pragma once
#include <string>

using namespace std;

class Team {

    private:
        string name;
        double skill_level;
        int final_score;

    public:
        Team();
        Team(string name, double s_lvl);
        string get_name() {return this->name;};
        double get_skill_level() {return this->skill_level;};
        int get_final_score() {return this->final_score;};
        void set_final_score(int score) {this->final_score = score;};

};