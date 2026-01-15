#ifndef MYGRADES_H
#define MYGRADES_H

#include <QDialog>

namespace Ui {
class MyGrades;
}

class MyGrades : public QDialog
{
    Q_OBJECT

public:
    explicit MyGrades(QWidget *parent = nullptr);
    ~MyGrades();

private:
    Ui::MyGrades *ui;
};

#endif // MYGRADES_H
