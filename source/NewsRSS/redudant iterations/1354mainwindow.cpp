#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include <QString>
//QString Spareinput;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText("test");
//    QDateTime currenttime = QDateTime::currentDateTimeUtc();
MainWindow::loop();

}
//    QFile inputfile("/home/pi/Newsroom/output.txt");
//    QDateTime currenttime = QDateTime::currentDateTimeUtc();
    //QDateTime futuretime = currenttime.addSecs(1000);
   // qDebug()<<currenttime;
   // qDebug()<<futuretime;
   // QDateTime nexttime = currenttime;

//    if (!inputfile.open(QIODevice::ReadOnly | QIODevice::Text))
//            return;

//    while (!inputfile.atEnd()) {
//        //QDateTime currenttime = QDateTime::currentDateTimeUtc();
//        QDateTime futuretime = currenttime.addSecs(60);
//        qDebug()<<currenttime;
//        qDebug()<<futuretime;
//        while(QDateTime::currentDateTimeUtc()<futuretime  ){
//            qDebug()<<futuretime;
//        ui->plainTextEdit->setPlainText(inputfile.readLine());
//        }

//     }
//    inputfile.close();

//}

//void loop(){
//    while (!inputfile.atEnd()) {
//         //QByteArray line = inputfile.readLine();
//        void delay();
//        ui->plainTextEdit->setPlainText(inputfile.readLine());

//     }

//}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loop(){
    QFile inputfile("/home/pi/Newsroom/output.txt");
    QDateTime currenttime = QDateTime::currentDateTimeUtc();
//    QString currenttimeStr = QDateTime::currentDateTimeUtc().toString();
    QString futuretimeStr = currenttime.addSecs(10).toString();
    if (!inputfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!inputfile.atEnd()) {
        QDateTime currenttime = QDateTime::currentDateTimeUtc();
        //QDateTime futuretime = currenttime.addSecs(10);
//        QString futuretimeStr = currenttime.addSecs(10).toString();
        QString currenttimeStr = QDateTime::currentDateTimeUtc().toString();

       // qDebug()<<currenttimeStr;
       // qDebug()<<futuretimeStr;
//        while(currenttime>futuretime  ){
//            //qDebug()<<futuretime;
//            ui->plainTextEdit->setPlainText(inputfile.readLine());
//            QDateTime currenttime = QDateTime::currentDateTimeUtc();
//             }
        while(currenttimeStr>futuretimeStr  ){
            qDebug()<<"Headline";

            ui->plainTextEdit->setPlainText(inputfile.readLine());

            futuretimeStr = currenttime.addSecs(1).toString();
            qDebug()<<ui->plainTextEdit->toPlainText();

             }
    }
   inputfile.close();

}


void MainWindow::on_plainTextEdit_textChanged()
{

}
