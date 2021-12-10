#ifndef FILE_H
#define FILE_H

// Library needed for processing files
#include <QFile>
#include<iostream>

class File
{
protected:
    QFile file;
    File(const QString&);
public:
    virtual ~File() = 0;
    virtual File* FromFileToObj() const = 0;
    virtual File* FromObjToFile() const = 0;
};

#endif // FILE_H
