#include "Bumblebee.h"
#include <string>

Bumblebee::Bumblebee()
    : _camaroSpeed(150), _camaroColor("Yellow"){}

Bumblebee::Bumblebee(unsigned int speed, std::string color)
    : _camaroSpeed(speed), _camaroColor(color){}
    
std::ostream& operator<<(std::ostream& os, const Bumblebee& t)
{
    os << "Bumblebee: level: " << t.getLevel() << "\n"
       << "strength: " << t.getStrength() << "\n"
       << "range: " << t.getRange() << "\n"
       << "fuel: " << t.getFuel() << "\n"
       << "ammo: " << t.getAmmo() << "\n"
       << "weapon: " << t.getWeapon() << "\n"
       << "CamaroSpeed: " << t.getCamaroSpeed() << "\n"
       << "CamaroColor: " << t.getCamaroColor() << "\n";
    return os;
}

unsigned int Bumblebee::getCamaroSpeed() const { return _camaroSpeed; }
void Bumblebee::setCamaroSpeed(unsigned int speed) { _camaroSpeed = speed; }

const std::string& Bumblebee::getCamaroColor() const { return _camaroColor; }
void Bumblebee::setCamaroColor(const std::string& color) { _camaroColor = color; }

