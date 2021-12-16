#ifndef XMLFILE_H
#define XMLFILE_H

// Library needed for processing XML documents
#include <QtXml>
#include "file.h"


class XmlFile: public File
{
private:
    QDomDocument xmlFile;
public:
    XmlFile(const QString& =QString());
    ~XmlFile() override;
    Obj* FromFileToObj() const override;
    void FromObjToFile(Obj*) override;

};

#endif // XMLFILE_H
