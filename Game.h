#ifndef CONSOLE_RPG_GAME_H
#define CONSOLE_RPG_GAME_H

#include "Enemy.h"
#include "Player.h"

class Game {
    enum Event {
        MUSHROOM,
        BERRY,
        TRAP,
        GOLD,
        MONSTER,
        APPLE,
    };

    static bool eventHandler( Player &p);

    static void mushroom(Player &p);

    static void berry(Player &p);

    static bool trap(Player &p);

    static void gold(Player &p);

    static bool battle(Player &p);

    static void apple(Player &p);


public:
    static void run();

};
#endif //CONSOLE_RPG_GAME_H
