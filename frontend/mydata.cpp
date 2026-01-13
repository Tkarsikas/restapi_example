#include "mydata.h"
#include "ui_mydata.h"

MyData::MyData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyData)
{
    ui->setupUi(this);
}

MyData::~MyData()
{
    delete ui;
}

void MyData::setTestData(const QByteArray &newTestData)
{
    testData = newTestData;
    QJsonDocument jsonDoc=QJsonDocument::fromJson(testData);
    QJsonObject jsonObject=jsonDoc.object();
    ui->labelFName->setText(jsonObject["fname"].toString());
    ui->labelLName->setText(jsonObject["lname"].toString());
    ui->labelAddress->setText(jsonObject["streetaddress"].toString());
    ui->labelEmail->setText(jsonObject["email"].toString());
}
