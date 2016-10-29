#include <QApplication>
#include "logon.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logon *logon = new Logon();
    logon->setWindowFlags(Qt::FramelessWindowHint);
    logon->show();
    return a.exec();
}
