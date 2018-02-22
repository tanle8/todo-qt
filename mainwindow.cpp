// In the following code snippet, the first include is our class header.
// The second one is the include required by the generated class `Ui::MainWindow`.
// This include is required as we only use a forward declaration in the header.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

    // [Signals&Slots] This a connection and how we will connect signals and slots:
    // - `sender`: This is the object that will send the **signal**.
    //          In this example, it is the `QPushButton` named `addTaskButton` added from the `UI` designer.
    // - `&<Sender>::<signalName>`: This is the pointer to the member signal function.
    //          Here, we want to do something when the button is clicked signal is triggered.
    // - `receiver`: This is the object that will receive and handle the signal.
    //          In our case, it is the `QApplication` object created in `main.cpp`.
    // - `&Receiver::slotName`: This is a pointer to one of the receiver's member `slot functions`.
    //          In this example, we use the built-in `quit()` slot from `QApplication`,
    //          which will exit the application.
    // [Updated] the updated connect now calls our custom slot instead of quiting the application.
    connect (ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    // [Qt tips] You can connect a signal to another signal.
    // The second signal will be emitted when the first one is triggered.
    // Now that you
}

// As we initialize a pointer in the constructor, it must be cleaned in
// the destructor:
MainWindow::~MainWindow()
{
    delete ui;
}

// We tell the computer to create a new function (slot) called `addTask()`.
void MainWindow::addTask ()
{
    // Qt provides an efficient way of displaying debug information with the `QDebug` class.
    // An wasy way to obtain a QDebug object is to call the `qDebug()` function.
    // Then, you can use the steam operator to send your debug information.
    qDebug() << "User clicked on the button!";
}
