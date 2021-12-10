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
    XmlFile();
    XmlFile(const QString&);
    ~XmlFile() override;
    Obj FromFileToObj() const override;
    XmlFile* FromObjToFile(const Obj&) const override;

};

#endif // XMLFILE_H
