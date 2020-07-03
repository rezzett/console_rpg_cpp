#ifndef CONSOLE_RPG_ENEMY_H
#define CONSOLE_RPG_ENEMY_H

#include "GameOjbect.h"

class Enemy : public GameObject {
    enum EnemyType {
        BOAR, WOLF, GOBLIN, ORC, DRAGON
    };
    EnemyType _type;
    int _gold;
public:
    Enemy(int hp, int dmg, int crit, int dodge, int gold, EnemyType type)
            : GameObject(hp, dmg, crit, dodge), _type(type), _gold(gold) {}

    static constexpr int enemyTmpl[5][5]{
            {14,  4,  15, 15, 3},
            {9,   6,  10, 10, 5},
            {12,  3,  20, 45, 15},
            {25,  10, 10, 10, 30},
            {100, 30, 0,  0,  200},
    };

    static Enemy randomSpawn() {
        int rnd = dice(0, 101);

        if (30 < rnd and rnd < 60)
            return Enemy(enemyTmpl[1][0], enemyTmpl[1][1], enemyTmpl[1][2], enemyTmpl[1][3], enemyTmpl[1][4], WOLF);
        else if (60 < rnd and rnd < 80)
            return Enemy(enemyTmpl[2][0], enemyTmpl[2][1], enemyTmpl[2][2], enemyTmpl[2][3], enemyTmpl[2][4], GOBLIN);
        else if (80 < rnd and rnd < 95)
            return Enemy(enemyTmpl[3][0], enemyTmpl[3][1], enemyTmpl[3][2], enemyTmpl[3][3], enemyTmpl[3][4], ORC);
        else if (rnd > 95 and rnd < 101)
            return Enemy(enemyTmpl[4][0], enemyTmpl[4][1], enemyTmpl[4][2], enemyTmpl[4][3], enemyTmpl[4][4], DRAGON);
        else
            return Enemy(enemyTmpl[0][0], enemyTmpl[0][1], enemyTmpl[0][2], enemyTmpl[0][3], enemyTmpl[0][4], BOAR);
    }

    std::string name() {
        switch (_type) {
            case BOAR :
                return "Boar";
            case WOLF :
                return "Wolf";
            case GOBLIN :
                return "Goblin";
            case ORC :
                return "Orc";
            case DRAGON :
                return "Dragon";
            default:
                return "Unknown";
        }
    }

    int gold() const { return _gold; }
};

#endif //CONSOLE_RPG_ENEMY_H
