#include "obj.h"

Obj::Date::Date(const std::string& year, const std::string& month) : _year(year), _month(month) {}

Obj::Component::Component(int b2b, int b2c, int b2g) :
    _b2b(b2b), _b2c(b2c), _b2g(b2g) {}

Obj::Obj(const std::string& year, const std::string& month, int b2b, int b2c, int b2g) :
    date(year, month), component(b2b, b2c, b2g) {}

std::string Obj::Date::get() const {
    return _year + " " + _month;
}

std::string Obj::Date::month() const {
    return _month;
}

std::string Obj::Date::year() const {
    return _year;
}

std::string Obj::getDate() const{
    return date.get();
}

int Obj::Component::getB2B() const {
    return _b2b;
}

int Obj::Component::getB2C() const {
    return _b2c;
}

int Obj::Component::getB2G() const {
    return _b2g;
}

std::string Obj::getMonth() const {
    return date.month();
}

std::string Obj::getYear() const {
    return date.year();
}

int Obj::getB2BValue() const {
    return component.getB2B();
}

int Obj::getB2CValue() const {
    return component.getB2C();
}

int Obj::getB2GValue() const {
    return component.getB2G();
}

int  Obj::getB2BPercentage() const{
    return (component.getB2B() * 100) / getTotalValue();
}

int  Obj::getB2CPercentage() const{
    return (component.getB2C() * 100) / getTotalValue();
}

int  Obj::getB2GPercentage() const{
    return (component.getB2G() * 100) / getTotalValue();
}

int Obj::getMaxValue() const {
    int max = component.getB2B();
    if(max < component.getB2C()) max = component.getB2C();
    if(max < component.getB2G()) max = component.getB2G();
    return max;
}

int Obj::getMinValue() const {
    int min = component.getB2B();
    if(min > component.getB2C()) min = component.getB2C();
    if(min > component.getB2G()) min = component.getB2G();
    return min;
}

int Obj::getTotalValue() const {
    return component.getB2B() + component.getB2C() + component.getB2G();
}

int Obj::getTotalPercentage() const {
    return getB2BPercentage() + getB2CPercentage() + getB2GPercentage();
}

bool Obj::isValid() const {
    return component.getB2B() != 0 || component.getB2C() != 0 || component.getB2G() != 0;
}
