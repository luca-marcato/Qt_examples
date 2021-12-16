#include "mainwindow.h"
#include <QApplication>

#include "obj.h"
#include "xmlfile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a obj by reading the file content
    XmlFile file1("template.xml");
    Obj* obj = file1.FromFileToObj();
    std::cout<<"OBJ: " << obj <<std::endl;

    MainWindow w;
    w.show();

    return a.exec();
}
