#ifndef CONSOLE_RPG_PLAYER_H
#define CONSOLE_RPG_PLAYER_H

#include <iostream>
#include "GameOjbect.h"

class Player : public GameObject {
    int _score, _level;
    std::string _name;
public:
    static const int state = 15;
    static const int init_dmg = 4;

    Player(int hp, int dmg, int crit, int dodge)
            : GameObject(hp, dmg, crit, dodge), _level(1), _score(0), _name("Player") {}

    bool tryRunAway() const { return dice(0, 2) == 1; }

    void levelUp() {
        ++_level;
        ++_dmg;
        ++_crit;
        ++_dodge;
        _hp = state + _level;
    }

    int level() const { return _level; }

    int score() const { return _score; }

    void score(int val) { _score = val; }

    std::string name() const { return _name; }

    void askName() {
        std::cout << "Enter your name: ";
        std::cin >> _name;
    }

    bool isWin() const { return _level > 30; }

    void reset() {
        _hp = state;
        _score = 0;
        _level = 1;
        _crit = state;
        _dodge = state;
        _dmg = init_dmg;

    }
};

#endif //CONSOLE_RPG_PLAYER_H
