#include "Weapon.h"
#include <iostream> 
   

void Weapon::printInfo() const {
     std::cout << "Type: " << type << std::endl;
     std::cout << "Damage: " << damage << std::endl;
}
   

