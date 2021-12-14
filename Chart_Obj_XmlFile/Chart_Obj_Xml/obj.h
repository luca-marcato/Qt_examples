#ifndef OBJ_H
#define OBJ_H

#include<iostream>

class Obj
{
private:
    int val1;
    int val2;
    int val3;
    std::string name;
public:
    Obj(int =0, int =0, int =0, const std::string& =std::string());
    int getVal1() const;
    int getVal2() const;
    int getVal3() const;
    std::string getName() const;
    void setVal1(int);
    void setVal2(int);
    void setVal3(int);
    void setName(std::string);
};

std::ostream& operator <<(std::ostream&, const Obj&);

#endif // OBJ_H
