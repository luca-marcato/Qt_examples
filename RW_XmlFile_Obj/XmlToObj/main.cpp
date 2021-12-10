#include <QCoreApplication>
#include "xmlfile.h"
#include "obj.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    XmlFile data("billofmaterial.xml");
    Obj obj(&data);

    std::cout<<obj;

    return a.exec();
}
