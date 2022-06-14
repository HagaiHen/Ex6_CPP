#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "doctest.h" 

#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

using namespace std;

TEST_CASE ("Team") {

    CHECK_THROWS(Team* t = new Team("t1", 5));
    CHECK_NOTHROW(Team* team = new Team("t3", 0.1));
    Team* team = new Team("t3", 0.1);

    CHECK(team->get_name() == "t3");
    CHECK(team->get_skill_level() == 0.1);
    CHECK(team->get_final_score() == 0);

}


TEST_CASE ("Game") {
    Team* team1 = new Team("t3", 0.1);
    Team* team2 = new Team("t3", 0.1);


    CHECK_THROWS(Game* g = new Game(team1, team1));
    CHECK_THROWS(Game* g = new Game(team1, team2));

    Team* home = new Team("t1", 0.4);
    Team* away = new Team("t2", 0.3);

    CHECK_NOTHROW(Game* g = new Game(home, away));

    Game* game = new Game(home, away);

    CHECK(game->get_away() == away);
    CHECK(game->get_home() == home);

    CHECK(game->get_status() == 0);

    game->start_game();

    CHECK(game->get_status() == 2);

    CHECK (game->get_home_score() <= 100);
    CHECK (game->get_home_score() >= 55);

    CHECK (game->get_away_score() <= 100);
    CHECK (game->get_away_score() >= 50);

}


TEST_CASE ("Leauge") {

    Leauge* l1 = new Leauge();
    Team* t = new Team("a", 0.5);
    for (int i = 0; i < 20; i++) {
        CHECK_FALSE(l1->contains(t));
    }

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
    };

    CHECK(rnd_list.size() == 10);

    Leauge* l2 = new Leauge(rnd_list);

    CHECK(rnd_list.size() == 20);
   
}


TEST_CASE ("Schedule") {
    Leauge* leauge =  new Leauge();

    Schedule* sche  = new Schedule(leauge);

    for (int i = 0; i < 40; i++) {
        sche->next_round();
    }

    CHECK_THROWS(sche->next_round());
    
}