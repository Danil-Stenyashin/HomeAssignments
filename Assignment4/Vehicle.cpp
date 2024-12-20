#include <string>
#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle(const std::string& name, int speed) : name(name), speed(speed) {}

const std::string& Vehicle::getName() const
{
    return name;
}
const int& Vehicle::getSpeed() const
{
    return speed;
}

void Vehicle::setName(const std::string& name)
{
    this->name = name;
}
void Vehicle::setSpeed(int speed)
{
    this->speed = speed;
}
