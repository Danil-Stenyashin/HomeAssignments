#ifndef MEGATRON_H
#define MEGATRON_H

#include "Transformer.h"

class Megatron : public Transformer {
public:
  Megatron();

    bool transformToTank();
    bool transformToRobot();
};

#endif // MEGATRON_H
