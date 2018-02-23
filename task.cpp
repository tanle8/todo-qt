#include "task.h"
#include "ui_task.h"

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
}

Task::~Task()
{
    delete ui;
}

// The implementation is straight-forward; we store the information in our `ui->checkbox` and
//  the `name()`and `isCompleted` getters take their data from the `ui-checkbox`.


void Task::setName (const QString& name)
{
    ui->checkBox->setText (name);
}

QString Task::name () const
{
    return ui->checkBox->text ();
}

bool Task::isCompleted () const
{
    return ui->checkBox->isChecked ();
}
