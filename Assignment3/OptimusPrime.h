#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "Transformer.h"

class OptimusPrime : public Transformer {
public:
    OptimusPrime();  

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

