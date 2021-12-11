#include <QCoreApplication>
#include "xmlfile.h"
#include "obj.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //create a obj by reading the file content
    XmlFile file1("billofmaterial.xml");
    Obj obj1 = file1.FromFileToObj();
    std::cout<<"OBJ 1: " << obj1 <<std::endl;

    //create a file by reading the obj content
    std::string aa = "as";
    std::string b = "asqw";
    std::string c = "re";
    std::string d = "New Text";
    Obj obj2(aa,b,c,d);
    XmlFile file2("file.xml");
    file2.FromObjToFile(obj2);
    std::cout<<"OBJ 2: " << obj2 <<std::endl;

    //update a file by reading the obj content
    XmlFile file3("file.xml");
    obj2.setBomBoard("Motor controller");
    obj2.setBomYear("2015");
    obj2.setComponentId("R2");
    file3.FromObjToFile(obj2);
    std::cout<<"OBJ 2: (new) " << obj2 <<std::endl;

    return a.exec();
}
