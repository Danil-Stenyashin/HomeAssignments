#include "Transformer.h"
#include <iostream>  // Для оператора <<

Transformer::Transformer() : _level(1), _strength(100), _range(5), _fuel(100), _ammo(100), _weapon(new Weapon("Default Weapon", 10)) {}

Transformer::Transformer(unsigned int level, unsigned int strength, unsigned int range, unsigned int fuel, unsigned int ammo, const Weapon& weapon)
    : _level(level), _strength(strength), _range(range), _fuel(fuel), _ammo(ammo), _weapon(new Weapon(weapon)) {}

Transformer::~Transformer() {
    delete _weapon;
}

bool Transformer::move() { return true; }

bool Transformer::turn(Direction dir) { return true; }

bool Transformer::jump() { return true; }

bool Transformer::fire() {
    if (_ammo > 0) {
        _ammo--;
        return true;
    }
    return false;
}

bool Transformer::ultimate() { return true; }

bool Transformer::transform() { return true; }

unsigned int Transformer::getLevel() const { return _level; }

void Transformer::setLevel(unsigned int level) { _level = level; }

unsigned int Transformer::getStrength() const { return _strength; }

void Transformer::setStrength(unsigned int strength) { _strength = strength; }

unsigned int Transformer::getRange() const { return _range; }

void Transformer::setRange(unsigned int range) { _range = range; }

unsigned int Transformer::getFuel() const { return _fuel; }

void Transformer::setFuel(unsigned int fuel) { _fuel = fuel; }

unsigned int Transformer::getAmmo() const { return _ammo; }

void Transformer::setAmmo(unsigned int ammo) { _ammo = ammo; }

const Weapon& Transformer::getWeapon() const { return *_weapon; }

void Transformer::setWeapon(const Weapon& weapon) {
    delete _weapon;
    _weapon = new Weapon(weapon);
}

// Оператор сравнения
bool Transformer::operator>(const Transformer& other) const {
    return _strength > other._strength;
}

bool Transformer::operator<(const Transformer& other) const {
    return _strength < other._strength;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Transformer& t) {
    os << "Level: " << t.getLevel() << "\n";
    os << "Strength: " << t.getStrength() << "\n";
    os << "Range: " << t.getRange() << "\n";
    os << "Fuel: " << t.getFuel() << "\n";
    os << "Ammo: " << t.getAmmo() << "\n";
    os << "Weapon: " << t.getWeapon().getType() << " (Damage: " << t.getWeapon().getDamage() << ")\n";
    return os;
}

