#include <QCoreApplication>

#include<iostream>
#include <QtXml>
#include <QtCore>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument doc;

    QDomElement billofmaterial = doc.createElement("BOM");
    billofmaterial.setAttribute("BOARD","Motor controller");
    billofmaterial.setAttribute("YEAR", "2014");

    QDomElement componentTag = doc.createElement("COMPONENT");
    componentTag.setAttribute("ID", "R1");

    QDomElement nameTag = doc.createElement(QString("NAME"));
    QDomText nameText = doc.createTextNode(QString("New Text"));
    nameTag.appendChild(nameText);

    componentTag.appendChild(nameTag);
    billofmaterial.appendChild(componentTag);
    doc.appendChild(billofmaterial);

    QFile file("billofmaterial.xml");

    if(file.open(QFile::WriteOnly | QFile::Text)){
            QTextStream in(&file);
            in<<doc.toString();
            file.flush();
            file.close();
            qDebug()<<"finished.";
        }else qDebug()<<"file open failed.";


    return a.exec();
}
