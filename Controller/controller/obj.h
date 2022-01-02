#ifndef OBJ_H
#define OBJ_H

#include<iostream>

class Obj
{
private:

    class Date {
      public:
        std::string year;
        std::string month;
        Date(const std::string&, const std::string&);
        std::string getDate() const;
    };
    Date date;

    class Component {
    public:
        int B2B;
        int B2C;
        int B2G;
        int id;
        Component(int, int, int, int);
    };
    Component component;

public:

    Obj(const std::string& ="",
        const std::string& ="",
        int =0, int =0, int =0, int =0);

    std::string getDate() const;
    std::string getMonth() const;
    std::string getYear() const;
    int  getB2BVal() const;
    int  getB2CVal() const;
    int  getB2GVal() const;
    //int  getComponentId() const;

    void setYear(std::string);
    void setMonth(std::string);
    void setB2BVal(int);
    void setB2CVal(int);
    void setB2GVal(int);
    //void setComponentId(int);

    int getMaxValue() const;
    int getTotalValue() const;
};

std::ostream& operator <<(std::ostream&, const Obj&);

#endif // OBJ_H
