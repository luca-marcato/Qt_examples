#include "xmlfile.h"

XmlFile::XmlFile(const QString& name): File(name), xmlFile() {
    xmlFile.setContent(&file);
    file.close();
}

XmlFile::~XmlFile() {}

Obj XmlFile::FromFileToObj() const {

    QDomElement mainTag = xmlFile.documentElement();
    if(!mainTag.isElement()) std::cerr << "FileFormatError: Tag MAIN not found";

    QDomElement componentTag = mainTag.firstChild().toElement();

    if(componentTag.isElement() && componentTag.tagName() == "COMPONENT") {
        //cicle
        int componentId = componentTag.attribute("ID").toInt();
        std::cout << componentId;
        QDomNodeList listComponent = componentTag.childNodes();

        QDomElement dateTag = list.at(0).toElement();
        if(dateTag.isElement() && date.dateTag() == "DATE") {
            QDomNodeList listDate = dateTag.childNodes();

        } else {
            std::cerr << "FileFormatError: Tag DATE not found";
        }

    } else {
        std::cerr << "FileFormatError: Tag COMPONENT not found";
    }

    /*QDomElement mainTag = xmlFile.documentElement();
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
            return Obj(bYear.toStdString(), bBoard.toStdString(), cId.toStdString(), name.toStdString());

        }
    }
    return Obj();
    */
}

void XmlFile::FromObjToFile(Obj* obj) {
    /*
    QDomDocument doc;
    QDomElement billofmaterial = doc.createElement("BOM");
    billofmaterial.setAttribute("BOARD", QString::fromStdString(obj.getBomBoard()));
    billofmaterial.setAttribute("YEAR", QString::fromStdString(obj.getBomYear()));

    QDomElement componentTag = doc.createElement("COMPONENT");
    componentTag.setAttribute("ID", QString::fromStdString(obj.getBomYear()));

    QDomElement nameTag = doc.createElement(QString("NAME"));
    QDomText nameText = doc.createTextNode(QString::fromStdString(obj.getName()));
    nameTag.appendChild(nameText);

    componentTag.appendChild(nameTag);
    billofmaterial.appendChild(componentTag);
    doc.appendChild(billofmaterial);

    if(file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream in(&file);
        in<<doc.toString();
        file.flush();
        file.close();
    }
    */
}
