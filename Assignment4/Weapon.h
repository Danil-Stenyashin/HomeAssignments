#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;
    int damage;

public:
    // Конструкторы
    Weapon(std::string t = "Default Weapon", int d = 10) : type(t), damage(d) {}

    // Геттеры
    std::string getType() const { return type; }
    int getDamage() const { return damage; }

    // Перегрузка оператора << для вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Weapon& w) {
        os << "Weapon: " << w.type << ", Damage: " << w.damage;
        return os;
    }

    // Перегрузка операторов сравнения
    bool operator<(const Weapon& w) const {
        return this->damage < w.damage;
    }

    bool operator>(const Weapon& w) const {
        return this->damage > w.damage;
    }

    bool operator==(const Weapon& w) const {
        return this->damage == w.damage;
    }
};

#endif // WEAPON_H

