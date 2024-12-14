#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <iostream>

class Transformer {
public:
    virtual ~Transformer() = default;

    virtual void transform() const {
        std::cout << "Transform method called from Transformer" << std::endl;
    }

    virtual void openFire() const {
        std::cout << "OpenFire method called from Transformer" << std::endl;
    }

    virtual void ultimate() const {
        std::cout << "Ultimate method called from Transformer" << std::endl;
    }
};
