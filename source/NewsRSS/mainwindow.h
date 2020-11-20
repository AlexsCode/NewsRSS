#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString Spareinput;  //headline name
    QStringList SpareList; //list of headlines
    int n=0; //headline index


private slots:
    void Readin(); //function for reading file contence to display
    void print(); // function for displaying contence on ui

private:
    Ui::MainWindow *ui; //ui object
    QTimer *timer; //timer for slot timing

};

#endif // MAINWINDOW_H
