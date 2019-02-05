#include "firstpage.h"
#include <QObject>
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("C:\\Users\\User\\Documents\\c2\\Resource\\main.png"));
    firstPage w;
    w.show();
    return a.exec();
}
