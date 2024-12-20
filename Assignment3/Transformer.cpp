#include "Transformer.h"

Transformer::Transformer() : _level(1), _strength(100), _range(5), _fuel(100), _ammo(100), _weapon(new Weapon("Default Weapon", 10)) {}

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

Transformer::Transformer()
    : _level(1), _strength(100), _range(5), _fuel(100), _ammo(100),
      _weapon(new Weapon("Default Weapon", 10)),
      _primaryWeapon("Sword", 20), _secondaryWeapon("Shield", 15) {}

const Weapon& Transformer::getPrimaryWeapon() const { return _primaryWeapon; }
void Transformer::setPrimaryWeapon(const Weapon& weapon) { _primaryWeapon = weapon; }

const Weapon& Transformer::getSecondaryWeapon() const { return _secondaryWeapon; }
void Transformer::setSecondaryWeapon(const Weapon& weapon) { _secondaryWeapon = weapon; }

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

    
