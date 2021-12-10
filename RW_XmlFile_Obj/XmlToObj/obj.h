#ifndef OBJ_H
#define OBJ_H

#include<iostream>

#include "file.h"

class Obj
{
private:
    std::string bomYear;
    std::string bomBoard;
    std::string componentId;
    std::string name;
    File* file;
public:
    Obj(const std::string& =std::string(),
        const std::string& =std::string(),
        const std::string& =std::string(),
        const std::string& =std::string(),
        File* =nullptr);
    std::string getBomYear() const;
    std::string getBomBoard() const;
    std::string getComponentId() const;
    std::string getName() const;
    void setBomYear(std::string);
    void setBomBoard(std::string);
    void setComponentId(std::string);
    void setName(std::string);
    void saveToFile() const;
};

std::ostream& operator <<(std::ostream&, const Obj&);

#endif // OBJ_H
