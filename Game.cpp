#include <conio.h>
#include "Game.h"

bool Game::eventHandler(Player &p) {
    int rnd = Player::dice(0, 6);
    switch (rnd) {
        case MUSHROOM:
            mushroom(p);
            return false;
        case TRAP:
            return trap(p);
        case BERRY:
            berry(p);
            return false;
        case MONSTER:
            return battle(p);
        case GOLD :
            gold(p);
            return false;
        case APPLE:
            apple(p);
            return false;
        default:
            std::cout << "Nothing happening....\n";
            return false;
    }
}


void Game::run() {
    Player p(Player::state, Player::init_dmg, Player::state, Player::state);
    p.askName();


    gameloop:
    while (true) {
        if (eventHandler(p)) break;
        std::cout << "Press Enter to continue...\n";
        _getch();
    }
    std::cout << "Play again? (y/n)?";
    char replay;
    std::cin >> replay;
    if (replay == 'y' or replay == 'Y') {
        p.reset();
        goto gameloop;
    }
}

void Game::mushroom(Player &p) {
    std::cout << "You found a mushroom! Your crit increased by 1!\n";
    p.crit(p.crit() + 1);
}

void Game::berry(Player &p) {
    std::cout << "You found a berry! Your dodge increased by 1!\n";
    p.dodge(p.dodge() + 1);
}

bool Game::trap(Player &p) {
    std::cout << "You are trapped! Your hp decreased by 2!\n";
    p.hp(p.hp() - 2);
    return p.isDead();
}

void Game::gold(Player &p) {
    int rnd = Player::dice(1, 30);
    std::cout << "You found some gold! Your score increased by " << rnd << std::endl;
    p.score(p.score() + rnd);
}

bool Game::battle(Player &p) {
    Enemy enemy = Enemy::randomSpawn();
    std::cout << "You met a " << enemy.name() << "!\n";
    while (true) {
        std::cout << "(F)ight of (R)un?:";
        char decision;
        std::cin >> decision;
        if (decision == 'R' or decision == 'r' and p.tryRunAway()) {
            std::cout << "You successfully ran away!\n";
            return false;
        } else if (decision == 'R' or decision == 'r') {
            std::cout << "You couldn`t to escape !\n";
        }

        AttackResult result = p.attack(enemy);
        std::cout << result.miss << result.crit << "You hit " << enemy.name() <<
                  " " << result.damage << " damage! " << enemy.name() << " hp is: " << enemy.hp() << " \n";
        if (enemy.isDead()) {
            std::cout << "You killed the " << enemy.name() <<" you got " << enemy.gold() <<  " gold!You got a new level!\n";
            p.levelUp();
            p.score(p.score() + enemy.gold());
            std::cout << "Your level is:" << p.level() << " your score: " << p.score() << "!\n";
            if (p.isWin()) return true;
            return false;
        }

        AttackResult enemyRes = enemy.attack(p);
        std::cout << enemyRes.miss << enemyRes.crit << enemy.name() << " hit " << "you " <<
                  " " << enemyRes.damage << " damage! " << p.name() << " hp is: " << p.hp() << " \n";
        if (p.isDead()) {
            std::cout << "You died! Game over!\n Score: " << p.score() << " Level: " << p.level() << std::endl;
            return true;
        }
    }
}

void Game::apple(Player &p) {
    std::cout << "You found an apple!Your hp increased by 1!\n";
    p.hp(p.hp() + 1);
}



