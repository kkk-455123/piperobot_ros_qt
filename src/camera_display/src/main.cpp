#include "../include/camera_display/mainwindow.h"

#include <QApplication>

// mysql相关
// #include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(argc, argv);
    // w.show();
    w.showFullScreen();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    return a.exec();
}
