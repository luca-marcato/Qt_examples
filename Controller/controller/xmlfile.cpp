#include "xmlfile.h"

XmlFile::XmlFile(const QString& name): File(name), xmlFile() {
    if(!name.isEmpty()) {
        xmlFile.setContent(&file);
        file.close();
    }
}

XmlFile::XmlFileFormatError::XmlFileFormatError(const QString& error) : errorMsg(error) {}

const QString& XmlFile::XmlFileFormatError::message() const {
    return errorMsg;
}

void XmlFile::setFile(const QString& name) {
    file.setFileName(name);
    file.open(QIODevice::ReadWrite);
    xmlFile.setContent(&file);
    file.close();
}

Obj* XmlFile::FromFileToObj() const {

    QDomElement mainTag = xmlFile.documentElement();

    if(mainTag.isNull()) throw(XmlFileFormatError("FileFormatError: Tag MAIN not found"));

    QDomElement mainBody = mainTag.firstChild().toElement();

    std::string year;
    std::string month;
        if(mainBody.tagName() == "DATE") {
            QDomElement date = mainBody.firstChild().toElement();
            if(date.tagName() == "YEAR") {
                year = date.firstChild().toText().data().toStdString();
            } else {
                throw(XmlFileFormatError("FileFormatError: Expected YEAR but get : " + date.tagName()));
            }

            date = date.nextSibling().toElement();

            if(date.tagName() == "MONTH") {
                month = date.firstChild().toText().data().toStdString();
            } else {
                throw(XmlFileFormatError("FileFormatError: Expected MONTH but get : " + date.tagName()));
            }
        } else {
            throw(XmlFileFormatError("FileFormatError: Expected DATE but get : " + mainBody.tagName()));
        }

        mainBody = mainBody.nextSibling().toElement();

        int b2b;
        int b2c;
        int b2g;

        if(mainBody.tagName() == "VALUES") {
            QDomElement values = mainBody.firstChild().toElement();
            if(values.tagName() == "B2B") {
                b2b = values.firstChild().toText().data().toInt();
            } else {
                throw(XmlFileFormatError("FileFormatError: Expected B2B but get : " + values.tagName()));
            }

            values = values.nextSibling().toElement();

            if(values.tagName() == "B2C") {
                b2c = values.firstChild().toText().data().toInt();
            } else {
                throw(XmlFileFormatError("FileFormatError: Expected B2C but get : " + values.tagName()));
            }

            values = values.nextSibling().toElement();

            if(values.tagName() == "B2G") {
                b2g = values.firstChild().toText().data().toInt();
            } else {
                throw(XmlFileFormatError("FileFormatError: Expected B2G but get : " + values.tagName()));
            }

        } else {
            throw(XmlFileFormatError("FileFormatError: Expected VALUES but get : " + mainBody.tagName()));
        }

        return new Obj(year, month, b2b, b2c, b2g);
}

void XmlFile::FromObjToFile(const Obj* const obj) {

    QDomDocument doc;
    QDomElement mainTag = doc.createElement("MAINTAG");

    QDomElement dateTag = doc.createElement(QString("DATE"));

    QDomElement yearTag = doc.createElement(QString("YEAR"));
    QDomText yearText = doc.createTextNode(QString::fromStdString(obj->getYear()));
    yearTag.appendChild(yearText);

    QDomElement monthTag = doc.createElement(QString("MONTH"));
    QDomText monthText = doc.createTextNode(QString::fromStdString(obj->getMonth()));
    monthTag.appendChild(monthText);

    dateTag.appendChild(yearTag);
    dateTag.appendChild(monthTag);

    QDomElement valuesTag = doc.createElement(QString("VALUES"));

    QDomElement b2bTag = doc.createElement(QString("B2B"));
    QDomText b2bText = doc.createTextNode(QString::number(obj->getB2BValue()));
    b2bTag.appendChild(b2bText);

    QDomElement b2cTag = doc.createElement(QString("B2C"));
    QDomText b2cText = doc.createTextNode(QString::number(obj->getB2CValue()));
    b2cTag.appendChild(b2cText);

    QDomElement b2gTag = doc.createElement(QString("B2G"));
    QDomText b2gText = doc.createTextNode(QString::number(obj->getB2GValue()));
    b2gTag.appendChild(b2gText);

    valuesTag.appendChild(b2bTag);
    valuesTag.appendChild(b2cTag);
    valuesTag.appendChild(b2gTag);

    mainTag.appendChild(dateTag);
    mainTag.appendChild(valuesTag);
    doc.appendChild(mainTag);

    if(file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream in(&file);
        in<<doc.toString();
        file.flush();
        file.close();
    }

}
