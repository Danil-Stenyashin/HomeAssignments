#include <iostream>
#include <vector>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"

int main() {
    // Явное тестирование методов
    Autobot autobot;
    Decepticon decepticon;

    std::cout << "Testing individual objects:" << std::endl;
    autobot.transform();
    autobot.openFire();
    autobot.ultimate();

    decepticon.transform();
    decepticon.openFire();
    decepticon.ultimate();

    // Тестирование вызова методов из указателя базового класса
    Transformer* transformerPtr = &autobot;
    std::cout << "\nTesting methods through base class pointer:" << std::endl;
    transformerPtr->transform();
    transformerPtr->openFire();
    transformerPtr->ultimate();

    transformerPtr = &decepticon;
    transformerPtr->transform();
    transformerPtr->openFire();
    transformerPtr->ultimate();

    // Создание вектора указателей и вызов методов в цикле
    std::vector<Transformer*> transformers;
    for (int i = 0; i < 3; ++i) {
        transformers.push_back(new Autobot());
        transformers.push_back(new Decepticon());
        transformers.push_back(new Transformer());
    }

    std::cout << "\nTesting methods in a vector of pointers:" << std::endl;
    for (const auto& t : transformers) {
        t->transform();
        t->openFire();
        t->ultimate();
    }

    // Очистка памяти
    for (auto& t : transformers) {
        delete t;
    }

    return 0;
}

