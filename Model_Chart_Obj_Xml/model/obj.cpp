#include "obj.h"

Obj::Date::Date(const std::string& year, const std::string& month) :
    year(year), month(month) {}

Obj::Component::Component(const std::string& b2b, const std::string& b2c, const std::string& b2g, int id) :
    b2b(b2b), b2c(b2c), b2g(b2g), id(id) {}

Obj::Obj(const std::string& year, const std::string& month, const std::string& b2b, const std::string& b2c, const std::string& b2g, int componentId) :
    date(year, month), component(b2b, b2c, b2g, componentId) {}

std::string Obj::Date::getDate() const {
    return month + "-" + year;
}

std::string Obj::getDate() {
    return Date::getDate();
}

std::string Obj::getMonth() const {
    return Date::month;
}

std::string Obj::getYear() const {
    return Date::year;
}

std::string Obj::getB2BVal() const {
    return Component::B2B;
}

std::string Obj::getB2CVal() const {
    return Component::B2C;
}

std::string Obj::getB2GVal() const {
    return Component::B2G;
}

void Obj::setYear(std::string year) {
    Date::year = year;
}

void Obj::setMonth(std::string month) {
    Date::month = month;
}

void Obj::setB2BVal(std::string b2b) {
    Component::B2B = b2b;
}

void Obj::setB2CVal(std::string b2c) {
    Component::B2C = b2c;
}

void Obj::setB2GVal(std::string b2g) {
    Component::B2G = b2g
}

int Obj::getMaxValue() const {
    int max = Component::B2B;
    if(max < Component::B2C) max = Component::B2C;
    if(max < Component::B2G) max = Component::B2G;
    return max;
}

int Obj::getTotalValue() const {
    return Component::B2B + Component::B2C + Component::B2G;
}

std::ostream& operator <<(std::ostream& os, const Obj& obj) {
    return os << "Date: " << obj.getDate() <<std::endl
              << "Values: " << std::endl
              << "B2B: " << obj.getB2BVal()
              << " - B2C: " << obj.getB2CVal()
              << " - B2G: " << obj.getB2GVal();
}
