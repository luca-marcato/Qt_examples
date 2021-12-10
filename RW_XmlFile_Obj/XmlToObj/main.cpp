#include <QCoreApplication>
#include "xmlfile.h"
#include "obj.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Obj obj = XmlFile("billofmaterial.xml").FromFileToObj();
    //Obj obj(&XmlFile("billofmaterial.xml"))

    std::cout<<obj.getBomBoard();

    return a.exec();
}
