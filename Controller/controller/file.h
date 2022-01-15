#ifndef FILE_H
#define FILE_H

#include <QFile>
#include "obj.h"

class File
{
protected:
    QFile file;
    File(const QString&);
public:
    virtual ~File() =default;
    virtual void setFile(const QString&) = 0;
    virtual Obj* FromFileToObj() const = 0;
    virtual void FromObjToFile(const Obj* const) = 0;

    static bool Exist(const QString&);
};

#endif // FILE_H
