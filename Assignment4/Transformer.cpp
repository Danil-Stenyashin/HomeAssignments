
#include "Transformer.h"

Transformer::Transformer() : _level(1), _strength(100), _range(50), _fuel(100), _ammo(100), _weapon(nullptr) {}

bool Transformer::operator==(const Transformer& other) const {
    return _level == other._level && 
           _strength == other._strength && 
           _range == other._range &&
           _fuel == other._fuel &&
           _ammo == other._ammo;
}

bool Transformer::operator!=(const Transformer& other) const {
    return !(*this == other);
}

