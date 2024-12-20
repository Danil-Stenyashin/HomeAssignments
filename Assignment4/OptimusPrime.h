#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "Transformer.h"

class OptimusPrime : public Transformer {
public:
    OptimusPrime(); 
    
    OptimusPrime(unsigned int truckSpeed, unsigned int armorStrength, unsigned int leadershipLevel);
    
    friend std::ostream& operator<<(std::ostream& os, const OptimusPrime& t);

    bool transformToTruck();  
    bool transformToRobot();  


    unsigned int getTruckSpeed() const;
    void setTruckSpeed(unsigned int speed);

    unsigned int getArmorStrength() const;
    void setArmorStrength(unsigned int strength);

    unsigned int getLeadershipLevel() const;
    void setLeadershipLevel(unsigned int level);

private:
    unsigned int _truckSpeed;
    unsigned int _armorStrength;
    unsigned int _leadershipLevel;
};

#endif

