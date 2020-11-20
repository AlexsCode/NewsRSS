#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText("test");
    //MainWindow::loop();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Readin(){
    QFile inputfile("/home/pi/Newsroom/output.txt");
    if (!inputfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
     while (!inputfile.atEnd()) {


         ui->plainTextEdit->setPlainText(inputfile.readLine());
         MainWindow::delay();

     }inputfile.close();



}

void MainWindow::delay(){
    QString currenttimeStr = QDateTime::currentDateTimeUtc().toString();
    QString futuretimeStr = QDateTime::currentDateTimeUtc().addSecs(10).toString();
    QDateTime currenttime = QDateTime::currentDateTimeUtc();

    while(futuretimeStr>QDateTime::currentDateTimeUtc().toString()){
       qDebug()<<futuretimeStr;
        qDebug()<<currenttimeStr;
    }

}

void MainWindow::loop(){
    QFile inputfile("/home/pi/Newsroom/output.txt");
    QDateTime currenttime = QDateTime::currentDateTimeUtc();
    QString futuretimeStr = currenttime.addSecs(10).toString();
    if (!inputfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!inputfile.atEnd()) {
        QDateTime currenttime = QDateTime::currentDateTimeUtc();
        QString currenttimeStr = QDateTime::currentDateTimeUtc().toString();

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
    //Readin();

}
