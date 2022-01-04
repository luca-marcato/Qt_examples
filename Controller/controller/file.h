#ifndef FILE_H
#define FILE_H

// Library needed for processing files
#include <QFile>
#include<iostream>
#include "obj.h"

class File
{
protected:
    QFile file;
    File(const QString&);
public:
    virtual ~File() =default;
    virtual Obj* FromFileToObj() const = 0;
    virtual void FromObjToFile(Obj*) = 0;

    static bool Exist(const QString&);
};

#endif // FILE_H
