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
    XmlFile(const QString& = QString());
    void setFile(const QString&) override;
    Obj* FromFileToObj() const override;
    void FromObjToFile(const Obj* const) override;

    class XmlFileFormatError {
    private:
        QString errorMsg;
    public:
        XmlFileFormatError(const QString& =QString());
        const QString& message() const;
    };
};

#endif // XMLFILE_H
