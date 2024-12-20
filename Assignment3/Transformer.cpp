#include "Transformer.h"
#include "Vehicle.h"
#include "Weapon.h"
#include <iostream>

Transformer::Transformer() 
    : _level(1), _strength(100), _range(5), _fuel(100), _ammo(100), 
      _weapon(Weapon("Default Weapon", 10)){}

Transformer::~Transformer() {
    std::cout << "Transformer is dead" << std::endl; 
}


bool Transformer::move() {
    std::cout << "Transformer is moving!" << std::endl;
    return true;
}

bool Transformer::jump() {
    std::cout << "Transformer is jumping!" << std::endl;
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

const Weapon& Transformer::getWeapon() const
{
    return _weapon;
}
const Vehicle* Transformer::getVehicle() const
{
    return _vehicle;
}

void Transformer::setWeapon(const Weapon& weapon)
{
    this->_weapon = weapon;
}
void Transformer::assignVehicle(Vehicle* v)
{
    _vehicle = v;
}
