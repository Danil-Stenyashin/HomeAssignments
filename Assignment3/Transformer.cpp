#include "Transformer.h"
#include <iostream>

Transformer::Transformer() 
    : _level(1), _strength(100), _range(5), _fuel(100), _ammo(100), 
      _weapon(new Weapon("Default Weapon", 10)), _primaryWeapon("Plasma Gun", 50), _secondaryWeapon("Shield", 20) {}

Transformer::~Transformer() {
    delete _weapon;
}


bool Transformer::move() {
    std::cout << "Transformer is moving!" << std::endl;
    return true;
}

bool Transformer::jump() {
    std::cout << "Transformer is jumping!" << std::endl;
    return true;
}

bool Transformer::fire() {
    if (_ammo > 0) {
        std::cout << "Transformer is firing! Ammo left: " << _ammo - 1 << std::endl;
        _ammo--;
        return true;
    }
    std::cout << "Out of ammo!" << std::endl;
    return false;
}

bool Transformer::transform() {
    std::cout << "Transformer is transforming!" << std::endl;
    return true;
}

bool Transformer::ultimate() {
    std::cout << "Transformer is using ultimate attack!" << std::endl;
    return true;
}

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

const Weapon& Transformer::getWeapon() const {
    return _weapon != nullptr ? *_weapon : _primaryWeapon;
}

void Transformer::setWeapon(const Weapon& weapon) {
    if (_weapon != nullptr) {
        delete _weapon;
    }
    _weapon = new Weapon(weapon);
}

const Weapon& Transformer::getPrimaryWeapon() const { return _primaryWeapon; }
void Transformer::setPrimaryWeapon(const Weapon& weapon) { _primaryWeapon = weapon; }

const Weapon& Transformer::getSecondaryWeapon() const { return _secondaryWeapon; }
void Transformer::setSecondaryWeapon(const Weapon& weapon) { _secondaryWeapon = weapon; }

