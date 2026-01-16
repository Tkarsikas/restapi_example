#include "mydata.h"
#include "ui_mydata.h"

MyData::MyData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyData)
{
    ui->setupUi(this);
    connect(ui->btnSave, &QPushButton::clicked, this, &MyData::btnSaveClicked);
    manager=new QNetworkAccessManager(this);
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
    ui->textFname->setText(jsonObject["fname"].toString());
    ui->textLname->setText(jsonObject["lname"].toString());
    ui->textAddress->setText(jsonObject["streetaddress"].toString());
    ui->textEmail->setText(jsonObject["email"].toString());
}

void MyData::setUsername(const QString &newUsername)
{
    username = newUsername;
}

void MyData::setToken(const QByteArray &newToken)
{
    token = newToken;
}

void MyData::btnSaveClicked()
{
    QJsonObject jsonObject;
    jsonObject.insert("fname", ui->textFname->text());
    jsonObject.insert("lname", ui->textLname->text());
    jsonObject.insert("streetaddress", ui->textAddress->text());
    jsonObject.insert("email", ui->textEmail->text());
    jsonObject.insert("password", ui->textPassword->text());

    QString url=Environment::base_url()+"student/"+username;
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray myToken="Bearer "+token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    QJsonDocument jsonDoc(jsonObject);
    reply=manager->put(request, jsonDoc.toJson());
    connect(reply, &QNetworkReply::finished, this, &MyData::btnSaveslot);
}

void MyData::btnSaveslot()
{
    QByteArray respon_data=reply->readAll();
    qDebug()<<respon_data;
    this->close();
    reply->deleteLater();
}
