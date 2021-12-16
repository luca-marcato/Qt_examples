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
        Date(const std::string& =std::string(), const std::string& =std::string());
        std::string getDate() const;
    };
    Date date;

    class Component {
    public:
        std::string B2B;
        std::string B2C;
        std::string B2G;
        int id;
        Component(const std::string& =std::string(), const std::string& =std::string(), const std::string& =std::string(), int =0);
    };
    Component component;

public:

    Obj(const std::string& =std::string(),
        const std::string& =std::string(),
        const std::string& =std::string(),
        const std::string& =std::string(),
        const std::string& =std::string(),
        int =0);


    std::string getDate() const;
    std::string getMonth() const;
    std::string getYear() const;
    std::string  getB2BVal() const;
    std::string  getB2CVal() const;
    std::string  getB2GVal() const;

    void setYear(std::string);
    void setMonth(td::string);
    void setB2BVal(std::string);
    void setB2CVal(std::string);
    void setB2GVal(std::string);

    int getMaxValue() const;
    int getTotalValue() const;
};

std::ostream& operator <<(std::ostream&, const Obj&);

#endif // OBJ_H
