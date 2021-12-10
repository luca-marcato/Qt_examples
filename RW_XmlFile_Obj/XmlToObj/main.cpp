#include <QCoreApplication>
#include "xmlfile.h"
#include "obj.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    XmlFile file1("billofmaterial.xml");
    Obj obj1 = file1.FromFileToObj();
    std::cout<<obj1;

    std::string aa = "as";
    std::string b = "asqw";
    std::string c = "re";
    std::string d = "file";
    Obj obj2(aa,b,c,d);
    XmlFile file2("file.xml");
    file2.FromObjToFile(obj2);


    return a.exec();
}
