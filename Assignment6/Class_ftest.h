#ifndef Class_ftest_H
#define Class_ftest_H

#include <iostream>
#include <vector>


template <typename Type>
class MyTemplate
{
private:
    Type instance;
    int number;
    std::vector<float> vec;

public:
    MyTemplate(Type obj, int num, std::vector<float> v) : instance(obj), number(num), vec(v) {}

    bool foo()
    {
        return instance.bar(number, vec);
    }
};


template <>
class MyTemplate<int>
{
private:
    int instance;

public:
    MyTemplate(int obj) : instance(obj) {}

    bool foo()
    {
        return true;
    }
};


template <>
class MyTemplate<double>
{
private:
    double instance;

public:
    MyTemplate(double obj) : instance(obj) {}

    bool foo()
    {
        return false;
    }
};

#endif
