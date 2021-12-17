#include "file.h"

File::File(const QString& name) : file(name) {
    if(!file.open(QIODevice::ReadWrite)) {
        std::cerr << "Error while loading file" << std::endl;
    }
}
