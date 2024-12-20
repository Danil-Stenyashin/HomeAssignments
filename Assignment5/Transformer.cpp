#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Weapon.h"
#include "Transformer.h"



void Transformer::ulta() const {
    std::cout << "Executing ulta for Transformer: " << name << std::endl;
}

Transformer::Transformer()
    :name("Unknown"), health(100), level(1), strength(10), perception(10), weapon(), vehicle(nullptr){
    std::cout << "Transformer " << name << " is created." << std::endl;
}

Transformer::Transformer(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon)
    :name(name), health(health), level(level), strength(strength), perception(perception), weapon(weapon), vehicle(nullptr){
    std::cout << "Transformer " << name << " is created." << std::endl;
}

Transformer::~Transformer(){
    std::cout << "Transformer " << name << " is destroyed." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Transformer& t){
    os << "Transformer: " << t.getName() << "\n"
       << "Health: " << t.getHealth() << "\n"
       << "Level: " << t.getLevel() << "\n"
       << "Strength: " << t.getStrength() << "\n"
       << "Perception: " << t.getPerception() << "\n"
       << "Weapon: " << t.weapon.getType() << " (Damage: " << t.weapon.getDamage() << ") \n";
    return os;
}

bool Transformer::operator>(const Transformer& other) const{
    return strength > other.strength;
}

bool Transformer::operator<(const Transformer& other) const{
    return strength < other.strength;
}


const std::string& Transformer::getName() const{
    return name;
}
void Transformer::setName(const std::string& name){
    this->name = name;
}



const unsigned& Transformer::getHealth() const{
    return health;
}
void Transformer::setHealth(unsigned health){
    this->health = health;
}



const unsigned& Transformer::getLevel() const{
    return level;
}
void Transformer::setLevel(unsigned level){
    this->level = level;
}



const unsigned& Transformer::getStrength() const{
    return strength;
}
void Transformer::setStrength(unsigned strength){
    this->strength = strength;
}



const unsigned& Transformer::getPerception() const{
    return perception;
}
void Transformer::setPerception(unsigned perception){
    this->perception = perception;
}


const Weapon& Transformer::getWeapon() const{
    return weapon;
}
void Transformer::setWeapon(const Weapon& weapon){
    this->weapon = weapon;
}



const Vehicle* Transformer::getVehicle() const{
    return vehicle;
}
void Transformer::assignVehicle(Vehicle* v){
    vehicle = v;
}








void Transformer::transform() const{
    std::cout<<"transform Transformer" << std::endl;
}

void Transformer::openFire() const{
    std::cout<<"openFire Transformer" << std::endl;
}

