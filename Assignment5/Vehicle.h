#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>


class Vehicle
{
protected:
    std::string name;
    int speed;

public:
    Vehicle();

    Vehicle(const std::string& name, int speed);

    const std::string& getName() const;
    void setName(const std::string& name);
    
    const int& getSpeed() const;
    void setSpeed(int speed);

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& t);

    bool operator>(const Vehicle& other) const;
    bool operator<(const Vehicle& other) const;
};

#endif
