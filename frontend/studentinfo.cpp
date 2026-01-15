#include "studentinfo.h"
#include "ui_studentinfo.h"


StudentInfo::StudentInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
    manager=new QNetworkAccessManager(this);
    connect(ui->btnMyData, &QPushButton::clicked, this, &StudentInfo::fetchDataSlot);
    connect(ui->btnMyGrades, &QPushButton::clicked, this, &StudentInfo::btnMyGradeClicked);
}

StudentInfo::~StudentInfo()
{
    delete ui;
}

void StudentInfo::setUsername(const QString &newUsername)
{
    username = newUsername;
    ui->labelUsername->setText(username);
}

void StudentInfo::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<token;
}

void StudentInfo::fetchDataSlot()
{
    QString url=Environment::base_url()+"student/"+username;
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray myToken="Bearer "+token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    reply=manager->get(request);
    connect(reply, &QNetworkReply::finished, this, &StudentInfo::myDataSlot);
}

void StudentInfo::myDataSlot()
{
    QByteArray response=reply->readAll();
    qDebug()<<response;
    MyData *objMyData=new MyData(this);
    objMyData->setTestData(response);
    objMyData->show();

    reply->deleteLater();
}

void StudentInfo::btnMyGradeClicked()
{
    QString url=Environment::base_url()+"grade/"+username;
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray myToken="Bearer "+token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    reply=manager->get(request);
    connect(reply, &QNetworkReply::finished, this, &StudentInfo::myGradesSlot);
}

void StudentInfo::myGradesSlot()
{
    QByteArray response=reply->readAll();
    qDebug()<<response;
}

