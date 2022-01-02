#include "file.h"

File::File(const QString& name) : file(name) {
    file.open(QIODevice::ReadWrite);
}

bool File::SearchFile(const QString& fileName) {
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) return false;
    else return true;
}
