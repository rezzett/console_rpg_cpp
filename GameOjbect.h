#ifndef CONSOLE_RPG_GAMEOJBECT_H
#define CONSOLE_RPG_GAMEOJBECT_H

#include <cstdlib>
#include <string>

struct AttackResult {
    std::string miss;
    std::string crit;
    int damage;
};

class GameObject {
protected:
    int _hp, _dmg, _crit, _dodge;
public:
    GameObject(int hp, int dmg, int crit, int dodge)
            : _hp(hp), _dmg(dmg), _crit(crit), _dodge(dodge) {}

    static int dice(int low , int high) { return rand() % high + low; }
    int hp() const { return _hp; }
    void hp(int val) { _hp = val; }

    int dmg() const { return _dmg; }
    void dmg(int val) { _dmg = val; }

    int crit() const { return _crit; }
    void crit(int val) { _crit = val; }

    int dodge() const { return _dodge; }
    void dodge(int val) {_dodge = val; }

    int damage() const {
        if(dice(0, 101) > _crit ) return _dmg;
        return _dmg * 2;
    }

    bool reduceHp(int dmg) {
        if(dice(0, 101) > dodge()) {
            _hp -= dmg;
            return true;
        }
        return false;
    }

    bool isDead() const {
        return _hp < 1;
    }

    AttackResult attack(GameObject& other) const {
        int dmg = damage();
        std::string isCrit = dmg == _dmg ? "" : "CRITICAL! ";
        bool miss = other.reduceHp(dmg);
        if(!miss) return AttackResult{"MISS! ", "", 0};
        return AttackResult{"", isCrit, dmg};
    }
};

#endif //CONSOLE_RPG_GAMEOJBECT_H
