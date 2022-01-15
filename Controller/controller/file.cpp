#include "file.h"

File::File(const QString& name) : file(name) {
    if(!name.isEmpty()) file.open(QIODevice::ReadWrite);
}

bool File::Exist(const QString& fileName) {
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return false;
    return true;
}