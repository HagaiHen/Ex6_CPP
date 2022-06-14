#include "Game.hpp"
#include <iostream>


Game::Game::Game() {
    if (this->home_team->get_name() == this->away_team->get_name()) {
        throw invalid_argument("Same teams");
    }
    this->home_team = nullptr;
    this->away_team = nullptr;
    this->home_score = 0;
    this->away_score = 0;
    this->status = 0;
    this->result = -1;
}

Game::Game::Game(const Game &g) {
    this->home_team = g.home_team;
    this->away_team = g.away_team;
    this->home_score = g.home_score;
    this->away_score = g.away_score;
    this->status = g.status;
    this->result = g.result;
}

Game::Game::Game(Team* h, Team* a) {
    if (this->home_team->get_name() == this->away_team->get_name()) {
        throw invalid_argument("Same teams");
    }
    this->home_team = h;
    this->away_team = a;
    this->home_score = 0;
    this->away_score = 0;
    this->status = 0;
    this->result = -1;
}

void Game::start_game() {
    this->status = 1;
    int h_score = rand() % 101;
    int a_score = rand() % 101;

    if (h_score < 55) {
        h_score = 55;
    }

    if (a_score < 50) {
        a_score = 50;
    }

    if (this->home_team->get_skill_level() > this->away_team->get_skill_level()) {
        h_score += 10;
    } else {
        if (this->home_team->get_skill_level() < this->away_team->get_skill_level()) {
            a_score += 10;
        }
    }

    if (h_score > 100) {
        h_score = 100;
    }

    if (a_score > 100) {
        a_score = 100;
    }

    if (a_score > h_score) {
        this->result = 1;
    } else {
        this->result = 0;
    }
    
    this->home_score = h_score;
    this->away_score = a_score;
    this->status = 2;
}

Game::~Game() {
    delete this->home_team;
    delete this->away_team;
}

