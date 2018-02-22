#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString& name, QWidget *parent = 0);
    ~Task();

    // The constructor specifies a name, and as you can see there are no private fields storing
    // any state of the object. All this will be done in the form part.
    // We also added some getters and setters that will interact with the form.
    // It's better to have a model completely separated from the UI, but our example is simple
    // enough to merge them.
    // Moreover, `Task` implementation details are hidden from the outside world and can still
    // be refactored later on.
    void setName(const QString& name);
    QString name() const;
    bool isCompleted() const;

private:
    Ui::Task *ui;
};

#endif // TASK_H
