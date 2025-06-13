#include <string>
#include <iostream>
#include "Transformer.h"
#include "Decepticon.h"


Decepticon::Decepticon()
    : Transformer(), rank("No rank"), role("No role") {}

Decepticon::Decepticon(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role)
    : Transformer(name, health, level, strength, perception, weapon), rank(rank), role(role) {}

std::ostream& operator<<(std::ostream& os, const Decepticon& t)
{
    os << "Decepticon: " << t.getName() << "\n"
       << "Health: " << t.getHealth() << "\n"
       << "Level: " << t.getLevel() << "\n"
       << "Strength: " << t.getStrength() << "\n"
       << "Perception: " << t.getPerception() << "\n"
       << "Weapon: " << t.weapon.getType() << " (Damage: " << t.weapon.getDamage() << ") \n"
       << "Rank: " << t.getRank() << "\n"
       << "Role: " << t.getRole() << "\n";
    return os;
}




	
const std::string& Decepticon::getRank() const{
    return rank;
}
void Decepticon::setRank(const std::string& rank){
    this->rank = rank;
}


const std::string& Decepticon::getRole() const{
    return role;
}
void Decepticon::setRole(const std::string& role){
    this->role = role;
}





void Decepticon::transform() const{
    std::cout<<"transform Decepticon" << std::endl;
}

void Decepticon::openFire() const{
    std::cout<<"openFire Decepticon" << std::endl;
}

void Decepticon::ulta() const{
    std::cout<<"ulta Decepticon" << std::endl;
}

bool Decepticon::defend(){
    return (true);
}
bool Decepticon::heal(){
    return (true);
}
