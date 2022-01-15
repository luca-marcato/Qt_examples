#ifndef OBJ_H
#define OBJ_H

#include<iostream>

class Obj
{
private:

    class Date {
    private:
        std::string _year;
        std::string _month;
    public:
        Date(const std::string&, const std::string&);
        std::string get() const;
        std::string month() const;
        std::string year() const;
    };
    Date date;

    class Component {
    private:
        int _b2b;
        int _b2c;
        int _b2g;
    public:
        Component(int, int, int);
        int getB2B() const;
        int getB2C() const;
        int getB2G() const;
    };
    Component component;

public:

    Obj(const std::string& ="",
        const std::string& ="",
        int =0, int =0, int =0);

    std::string getDate() const;
    std::string getMonth() const;
    std::string getYear() const;
    int  getB2BValue() const;
    int  getB2CValue() const;
    int  getB2GValue() const;
    int  getB2BPercentage() const;
    int  getB2CPercentage() const;
    int  getB2GPercentage() const;

    int getMaxValue() const;
    int getMinValue() const;
    int getTotalValue() const;
    int getTotalPercentage() const;

    bool isValid() const;
};

#endif // OBJ_H
