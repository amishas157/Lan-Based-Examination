#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"


int main(int argc, char *argv[])
{

    // fetching I.P in argv[1] and port number in argv[2]

    QApplication a(argc, argv);
    int port = atoi(argv[2]);

    //open the main window
    MainWindow *w = new MainWindow(argv[1],port);

    w->show();

    return a.exec();
}
