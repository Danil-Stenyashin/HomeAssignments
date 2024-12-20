#include <iostream>
#include "Transformer.h"
#include "OptimusPrime.h"
#include "Bumblebee.h"
#include "Megatron.h"
#include <gtest/gtest.h>

int main() {

    Transformer transformer;
    OptimusPrime optimusPrime;
    Megatron megatron;
    Weapon myWeapon;
    Bumblebee bumblebee;  
    
    std::cout << "Default transformer:" << std::endl;
    std::cout << "Level: " << transformer.getLevel() << std::endl;
    std::cout << "Strength: " << transformer.getStrength() << std::endl;
    std::cout << "Range: " << transformer.getRange() << std::endl;
    std::cout << "Fuel: " << transformer.getFuel() << std::endl;
    std::cout << "Ammo: " << transformer.getAmmo() << std::endl;

    std::cout << "\nOptimus Prime:" << std::endl;
    std::cout << "Level: " << optimusPrime.getLevel() << std::endl;
    std::cout << "Strength: " << optimusPrime.getStrength() << std::endl;
    std::cout << "Range: " << optimusPrime.getRange() << std::endl;
    std::cout << "Fuel: " << optimusPrime.getFuel() << std::endl;
    std::cout << "Ammo: " << optimusPrime.getAmmo() << std::endl;
    std::cout << "Truck Speed: " << optimusPrime.getTruckSpeed() << std::endl;

    std::cout << "\nBumblebee:" << std::endl;
    std::cout << "Level: " << bumblebee.getLevel() << std::endl;
    std::cout << "Strength: " << bumblebee.getStrength() << std::endl;
    std::cout << "Range: " << bumblebee.getRange() << std::endl;
    std::cout << "Fuel: " << bumblebee.getFuel() << std::endl;
    std::cout << "Ammo: " << bumblebee.getAmmo() << std::endl;
    std::cout << "Camaro Speed: " << bumblebee.getCamaroSpeed() << std::endl;

    std::cout << "\nMegatron:" << std::endl;
    std::cout << "Level: " << megatron.getLevel() << std::endl;
    std::cout << "Strength: " << megatron.getStrength() << std::endl;
    std::cout << "Range: " << megatron.getRange() << std::endl;
    std::cout << "Fuel: " << megatron.getFuel() << std::endl;
    std::cout << "Ammo: " << megatron.getAmmo() << std::endl;
    
    return 0;
}

