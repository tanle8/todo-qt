// In the following code snippet, the first include is our class header.
// The second one is the include required by the generated class `Ui::MainWindow`.
// This include is required as we only use a forward declaration in the header.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    // In many cases, Qt generates a good piece of code using the
    // initializer list.
    // The `parent` argument is used to call the super-class constructor
    // `QMainWindow`.
    // Our private member variable `ui` is also initialized now.
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mTasks()

    // [C++ tip] As a best practice, try to always initialize member varianles in the initializer
    // list and respect the order of variable declarations. Your code will run faster and you will
    // avoid unnecessary variable copies.
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
}

// As we initialize a pointer in the constructor, it must be cleaned in the destructor:
// When `MainWindow` is released (remember, it's a stack variable allocated in the `main.cpp` file),
// it will call `delete ui`, which in turn will bring down the whole `QObject` hierarchy.
// This feature has interesting consequences:
// - First, if you use the QObject parenting model in your application, you will have much less
// memory to manage.
// - Second, it can collide with some new C++1 semantics, specifically the smart pointers.
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
    qDebug() << "Adding new task";
    // We created a new task and added it to our `mTask` vector. Because Task is a QWidget,
    // we also added it directly to the `tasksLayout`.
    // An important thing to note here is that we never managed this new task's memory.
    // Where is the `delete task` instruction? This is a key feature of the Qt Framework, the QObject
    // class parenting automatically handles object destrction.
    // In our case, the `ui->tasksLayout->addWidget(task)` call has an interesting side-effect;
    // the ownership of the task is transferred to `tasksLayout`.
    Task* task = new Task("Untitled task");
    mTasks.append (task);
    ui->tasksLayout->addWidget(task);
    // The `QObject*` parent defined in Task constructor is now `tasksLayout` and the `Task` destructor
    // will be called when `tasksLayout` releases its own memory by recursively iterating through its
    // children and calling their destructor.

    // QDialog
    bool ok;
    QString name = QInputDialog::getText (this,
                                          tr("Add task"),
                                          tr("Task name"),
                                          QLineEdit::Normal,
                                          tr("Untitled task"),
                                          &ok);
    if (ok && !name.isEmpty ()){
        qDebug() << "Adding new task";
        Task* task = new Task(name);
        mTasks.append (task);
        ui->tasksLayout->addWidget(task);
    }
}
