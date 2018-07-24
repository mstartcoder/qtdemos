#include "frmmain.h"
#include "systray.h"
#include <QApplication>
#include <QIcon>
#include <QSharedMemory>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSharedMemory singleton(a.applicationName());
     if(!singleton.create(1))
     {
         QMessageBox::warning(NULL, "Waring", "Program already running!");
         return false;
     }
    FrmMain w;
    SysTray sysTray;
    w.setWindowIcon(QIcon(":/app/config/setting.ico"));
    w.show();


    return a.exec();
}
