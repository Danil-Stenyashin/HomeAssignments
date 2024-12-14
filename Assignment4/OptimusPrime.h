#ifndef OPTIMUSP_H
#define OPTIMUSP_H

#include "Transformer.h"


class OptimusPrime : public Transformer {
public:
    OptimusPrime();

    bool transformToTruck();
    bool transformToRobot();

    unsigned int getTruckSpeed() const;
    void setTruckSpeed(uint speed);
private:
    unsigned int _truckSpeed;
};


#endif // OPTIMUSP_H
