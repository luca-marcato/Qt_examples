#include "obj.h"

Obj::Obj(File* f, const std::string& bYear, const std::string& bBoard, const std::string& cId, const std::string& name) :
    file(f), bomYear(bYear), bomBoard(bBoard), componentId(cId), name(name) {}
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
