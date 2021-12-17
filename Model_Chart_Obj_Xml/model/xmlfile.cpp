#include "xmlfile.h"

XmlFile::XmlFile(const QString& name): File(name), xmlFile() {
    xmlFile.setContent(&file);
    file.close();
}

XmlFile::~XmlFile() {}

//implementare le throw al posto degli std::cerr
Obj* XmlFile::FromFileToObj() const {

    QDomElement mainTag = xmlFile.documentElement();

    if(mainTag.isNull()) std::cerr << "FileFormatError: Tag MAIN not found";

    QDomElement component = mainTag.firstChild().toElement();

    while(!component.isNull()) {
        if(component.tagName() == "COMPONENT") {

            int componentId;

            if(!component.hasAttribute("ID")) std::cerr << "FileFormatError: Attribute ID not found";
            componentId = component.attribute("ID").toInt();

            std::string year;
            std::string month;

            //if(component.firstChild().isNull()) std::cerr << "FileFormatError: DATE or VALUES Tag not found";
            QDomElement componentBody = component.firstChild().toElement();
            if(componentBody.tagName() == "DATE") {
                //if(componentBody.firstChild().toElement().isNull()) std::cerr << "FileFormatError: YEAR or MONTH Tag not found";
                QDomElement date = componentBody.firstChild().toElement();
                if(date.tagName() == "YEAR") {
                    year = date.toText().data().toStdString();
                } else {
                    std::cerr << "FileFormatError: Expected DATE but get : " + date.tagName().toStdString();
                }
                if(date.tagName() == "MONTH") {
                    month = date.toText().data().toStdString();
                } else {
                    std::cerr << "FileFormatError: Expected DATE but get : " + date.tagName().toStdString();
                }
            } else {
                   std::cerr << "FileFormatError: Expected DATE but get : " + componentBody.tagName().toStdString();
            }

            int b2b;
            int b2c;
            int b2g;

            if(componentBody.tagName() == "VALUES") {
                QDomElement values = componentBody.firstChild().toElement();
                if(values.tagName() == "B2B") {
                    b2b = values.toText().data().toInt();
                } else {
                    std::cerr << "FileFormatError: Expected B2B but get : " + values.tagName().toStdString();
                }
                if(values.tagName() == "B2C") {
                    b2c = values.toText().data().toInt();
                } else {
                    std::cerr << "FileFormatError: Expected B2C but get : " + values.tagName().toStdString();
                }
                if(values.tagName() == "B2G") {
                    b2g = values.toText().data().toInt();
                } else {
                    std::cerr << "FileFormatError: Expected B2G but get : " + values.tagName().toStdString();
                }
            } else {
                std::cerr << "FileFormatError: Expected VALUES but get : " + componentBody.tagName().toStdString();
            }

            return new Obj(year, month, b2b, b2c, b2g, componentId);

            component = component.nextSibling().toElement();

        } else {
            std::cerr << "FileFormatError: Expected COMPONENT but get : " + component.tagName().toStdString();
        }
    }
    return new Obj();
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
