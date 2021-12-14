#include "obj.h"

Obj::Obj(int val1, int val2, int val3, const std::string& name) :
    val1(val1), val2(val2), val3(val3), name(name){}

int Obj::getVal1() const {
    return val1;
}

int Obj::getVal2() const {
    return val2;
}

int Obj::getVal3() const {
    return val3;
}

std::string Obj::getName() const {
    return name;
}

void Obj::setVal1(int val1) {
    val1 = val1;
}

void Obj::setVal2(int val2) {
    val2 = val2;
}

void Obj::setVal3(int val3) {
    val3 = val3;
}

void Obj::setName(std::string name) {
    name = name;
}

std::ostream& operator <<(std::ostream& os, const Obj& obj) {
    return os << "Bom Year: " << obj.getVal1()
              << " Bom Board: " << obj.getVal2()
              << " Component Id: " << obj.getVal3()
              << " Name: " << obj.getName();
}
