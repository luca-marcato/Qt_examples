#include "obj.h"

Obj::Date::Date(const std::string& year, const std::string& month) :
    year(year), month(month) {}

Obj::Component::Component(int b2b, int b2c, int b2g, int id) :
    B2B(b2b), B2C(b2c), B2G(b2g), id(id) {}

Obj::Obj(const std::string& year, const std::string& month, int b2b, int b2c, int b2g, int componentId) :
    date(year, month), component(b2b, b2c, b2g, componentId) {}

std::string Obj::Date::getDate() const {
    return year + " " + month;
}

std::string Obj::getDate() const{
    return date.getDate();
}

std::string Obj::getMonth() const {
    return date.month;
}

std::string Obj::getYear() const {
    return date.year;
}

int Obj::getB2BVal() const {
    return component.B2B;
}

int Obj::getB2CVal() const {
    return component.B2C;
}

int Obj::getB2GVal() const {
    return component.B2G;
}

int  Obj::getB2BPercent() const{
    return (component.B2B * 100) / getTotalValue();
}

int  Obj::getB2CPercent() const{
    return (component.B2C * 100) / getTotalValue();
}

int  Obj::getB2GPercent() const{
    return (component.B2G * 100) / getTotalValue();
}

void Obj::setYear(const std::string& year) {
    date.year = year;
}

void Obj::setMonth(const std::string& month) {
    date.month = month;
}

void Obj::setB2BVal(int b2b) {
    component.B2B = b2b;
}

void Obj::setB2CVal(int b2c) {
    component.B2C = b2c;
}

void Obj::setB2GVal(int b2g) {
    component.B2G = b2g;
}

int Obj::getMaxValue() const {
    int max = component.B2B;
    if(max < component.B2C) max = component.B2C;
    if(max < component.B2G) max = component.B2G;
    return max;
}

int Obj::getTotalValue() const {
    return component.B2B + component.B2C + component.B2G;
}

int Obj::getTotalPercent() const {
    return getB2BPercent() + getB2CPercent() + getB2GPercent();
}

std::ostream& operator <<(std::ostream& os, const Obj& obj) {
    return os << " OBJ: (DATE: " << obj.getDate()
              << " - VALUES: "
              << "b2b = " << obj.getB2BVal()
              << ", b2c = " << obj.getB2CVal()
              << ", b2g = " << obj.getB2GVal()<<")";
}
