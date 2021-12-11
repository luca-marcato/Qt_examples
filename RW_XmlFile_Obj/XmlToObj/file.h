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
    virtual ~File() = 0;
    virtual Obj FromFileToObj() const = 0;
    virtual void FromObjToFile(const Obj&) = 0;
};

#endif // FILE_H
