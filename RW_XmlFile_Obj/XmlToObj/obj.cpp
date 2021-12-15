#include "obj.h"

Obj::Obj(const std::string& bYear, const std::string& bBoard, const std::string& cId, const std::string& name) :
    bomYear(bYear), bomBoard(bBoard), componentId(cId), name(name){}

std::string Obj::getBomYear() const {
    return bomYear;
}

std::string Obj::getBomBoard() const {
    return bomBoard;
}

std::string Obj::getComponentId() const {
    return componentId;
}

std::string Obj::getName() const {
    return name;
}

void Obj::setBomYear(std::string bYear) {
    bomYear = bYear;
}

void Obj::setBomBoard(std::string bBoard) {
    bomBoard = bBoard;
}

void Obj::setComponentId(std::string cId) {
    componentId = cId;
}

void Obj::setName(std::string name) {
    name = name;
}

std::ostream& operator <<(std::ostream& os, const Obj& obj) {
    return os << "Bom Year: " << obj.getBomYear()
              << " Bom Board: " << obj.getBomBoard()
              << " Component Id: " << obj.getComponentId()
              << " Name: " << obj.getName();
}
