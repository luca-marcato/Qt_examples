#include "xmlfile.h"

XmlFile::XmlFile(const QString& name): File(name), xmlFile() {
    xmlFile.setContent(&file);
    file.close();
}

XmlFile::~XmlFile() {}

Obj XmlFile::FromFileToObj() const {
    QDomElement mainTag = xmlFile.documentElement();
    QString bYear = mainTag.attribute("YEAR");
    QString bBoard = mainTag.attribute("BOARD");

    QDomElement componentTag = mainTag.firstChild().toElement();

    //while(!Component.isNull())
    if(componentTag.tagName() == "COMPONENT") {
        QString cId = componentTag.attribute("ID");

        QDomElement child = componentTag.firstChild().toElement();
        //while (!Child.isNull())
        if(child.tagName() == "NAME") {
            QString name = child.firstChild().toText().data();
            return Obj(this, bYear.toStdString(), bBoard.toStdString(), cId.toStdString(), name.toStdString());

        }
    }
    return Obj();
}
