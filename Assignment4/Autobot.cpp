#include "Transformer.h"

class OptimusPrime : public Transformer {
public:
    OptimusPrime();

    bool transformToTruck();
    bool transformToRobot();

    unsigned int GetTruckSpeed() const;
    void setTruckSpeed(unsigned int speed);
  
    unsigned int OptimusPrime::getTruckSpeed() const { return _truckSpeed; }
private:
    unsigned int _truckSpeed;
};
