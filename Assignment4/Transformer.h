#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "Weapon.h"
#include <ostream>  // Для оператора <<

enum class Direction {
    Left,
    Right,
    Forward,
    Back
};

class Transformer {
public:
    Transformer();
    Transformer(unsigned int level, unsigned int strength, unsigned int range, unsigned int fuel, unsigned int ammo, const Weapon& weapon);  // Перегрузка конструктора
    ~Transformer();

    bool move();
    bool turn(Direction dir);
    bool jump();
    bool fire();
    bool ultimate();
    bool transform();

    unsigned int getLevel() const;
    void setLevel(unsigned int level);

    unsigned int getStrength() const;
    void setStrength(unsigned int strength);

    unsigned int getRange() const;
    void setRange(unsigned int range);

    unsigned int getFuel() const;
    void setFuel(unsigned int fuel);

    unsigned int getAmmo() const;
    void setAmmo(unsigned int ammo);

    const Weapon& getWeapon() const;
    void setWeapon(const Weapon& weapon);

    // Операторы сравнения
    bool operator>(const Transformer& other) const;
    bool operator<(const Transformer& other) const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Transformer& t);

private:
    unsigned int _level;
    unsigned int _strength;
    unsigned int _range;
    unsigned int _fuel;
    unsigned int _ammo;

    Weapon* _weapon;
};

#endif

