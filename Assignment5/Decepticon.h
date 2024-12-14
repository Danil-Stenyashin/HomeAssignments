#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon : public Transformer {
public:
    void transform() const override {
        std::cout << "Transform method called from Decepticon" << std::endl;
    }

    void openFire() const override {
        std::cout << "OpenFire method called from Decepticon" << std::endl;
    }

    void ultimate() const override {
        std::cout << "Ultimate method called from Decepticon" << std::endl;
    }
};

#endif // DECEPTICON_H
