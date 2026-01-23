#include "basepage.h"
#include "ui_basepage.h"

BasePage::BasePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BasePage)
{
    ui->setupUi(this);
}

BasePage::~BasePage()
{
    delete ui;
}
