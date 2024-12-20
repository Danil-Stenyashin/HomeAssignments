#include "Weapon.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Weapon& w) {
    os << "Type: " << w.getType() << ", Damage: " << w.getDamage();
    return os;
}
