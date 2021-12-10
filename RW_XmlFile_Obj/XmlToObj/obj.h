#ifndef OBJ_H
#define OBJ_H

#include<iostream>

class File;

class Obj
{
private:
    File* file;
    std::string bomYear;
    std::string bomBoard;
    std::string componentId;
    std::string name;
public:
    Obj(const File* =nullptr,
        const std::string& =std::string(),
        const std::string& =std::string(),
        const std::string& =std::string(),
        const std::string& =std::string());
    std::string getBomYear() const;
    std::string getBomBoard() const;
    std::string getComponentId() const;
    std::string getName() const;
};

#endif // OBJ_H
