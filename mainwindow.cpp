// In the following code snippet, the first include is our class header.
// The second one is the include required by the generated class `Ui::MainWindow`.
// This include is required as we only use a forward declaration in the header.

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    // In many cases, Qt generates a good piece of code using the
    // initializer list.
    // The `parent` argument is used to call the super-class constructor
    // `QMainWindow`.
    // Our private member variable `ui` is also initialized now.
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Now that `ui` is initialized, we must call the `setupUi` function
    // to initialize all widgets used by the `MainWindow.ui` design file:
    ui->setupUi(this);
}

// As we initialize a pointer in the constructor, it must be cleaned in
// the destructor:
MainWindow::~MainWindow()
{
    delete ui;
}
