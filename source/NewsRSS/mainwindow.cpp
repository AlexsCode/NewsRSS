#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <QTimer>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText("test");
    ui->plainTextEdit->setWindowState(Qt::WindowMaximized);
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowFlags(Qt::FramelessWindowHint);
    MainWindow::Readin();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(print()));
    timer->start(6000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Readin(){
    QFile inputfile("/home/pi/NewsRSS/assets/output.txt");
    if (!inputfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
     while (!inputfile.atEnd()) {
        Spareinput = inputfile.readLine();
        SpareList.append(Spareinput);
     }inputfile.close();

}


void MainWindow::print()
{   n++;
    QString ident = SpareList[n];
    ui->plainTextEdit->setPlainText(ident);
    if(n==(SpareList.size()-2)){
        n=1;
    }
}




