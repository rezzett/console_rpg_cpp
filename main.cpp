#include <iostream>
#include <ctime>
#include "Game.h"

int main() {
    srand(time(0));
    Game::run();

    return 0;
}
