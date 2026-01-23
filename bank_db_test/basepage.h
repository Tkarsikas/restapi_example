#ifndef BASEPAGE_H
#define BASEPAGE_H

#include <QDialog>

namespace Ui {
class BasePage;
}

class BasePage : public QDialog
{
    Q_OBJECT

public:
    explicit BasePage(QWidget *parent = nullptr);
    ~BasePage();

private:
    Ui::BasePage *ui;
};

#endif // BASEPAGE_H
