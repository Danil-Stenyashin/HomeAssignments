#ifndef My_Class_H
#define My_Class_H

#include <iostream>
#include <vector>

class Class1
{
public:
    bool bar(int num, std::vector<float>& vec){
        return num > 0;
    }

    int c_11(){
        return 52;
    }
    float c_12(){
        return 3.14f;
    }
    void c_13(){
        std::cout << "c_13\n";
    }
};

class Class2{
public:
    bool bar(int num, std::vector<float>& vec){
        return !vec.empty();
    }

    int c_21(){
        return 22;
    }
    float c_22(){
        return 2.25f;
    }
    void c_23(){
        std::cout << "c_23()\n";
    }
};

class Class3
{
public:
    bool bar(int num, std::vector<float>& vec){
        return num == -static_cast<int>(vec.size());
    }

    int c_31(){
        return -1;
    }
    float c_32(){
        return 1.288f;
    }
    void c_33()
    {
        std::cout << "c_33\n";
    }
};

#endif
