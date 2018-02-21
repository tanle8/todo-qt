#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // As usual, the `main.cpp` file contains the program entry point.
    // It will, by default, perform two actions:
    // - Instantiate and show your main window
    // - Instantiate a `QApplication` and execute the blocking main event loop
    QApplication a(argc, argv);
    MainWindow w;   // Instantiate a main window.
    w.show();       // Show a main window

    return a.exec();
}
