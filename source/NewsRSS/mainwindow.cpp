#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{ // sets up the main window and startup setings
    ui->setupUi(this); //creates ui from object

    ui->plainTextEdit->setPlainText("test"); //Initial Screen
    ui->plainTextEdit->setWindowState(Qt::WindowMaximized); //Fullscreens text display
    this->setWindowState(Qt::WindowMaximized);//Fullscreens the QT App
    this->setWindowFlags(Qt::FramelessWindowHint); //Removes any frames from the QT app
    MainWindow::Readin(); //Triggers the Read function - This reads the input file
    timer = new QTimer(this); //creates a Timer
    connect(timer,SIGNAL(timeout()),this,SLOT(print())); //connects the timer to print functions
    timer->start(30000); //starts timer set for 30,000 msec or 30 seconds
    //each time the timer reaches zenith, the timeout() signal is sent, this then activates the slot-> print() function
}

MainWindow::~MainWindow()
{
    delete ui; //deconstructor , removes ui when closing arg given
}

void MainWindow::Readin(){
    QFile inputfile("/home/pi/NewsRSS/assets/output.txt"); //sets the inputfile and gives path to it
    if (!inputfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return; //inline if loop checks if file is open, if its not it opens as read only.
     while (!inputfile.atEnd()) { // loops until it has read the full file (reaches EOF)
        Spareinput = inputfile.readLine(); //Reads each line from the file into a single string
        SpareList.append(Spareinput); //then appends the line into a list. the string Spareinput resets each loop, the list never resets
     }inputfile.close();

}


void MainWindow::print()
{   n++; //print sets the text box to the headline. n is the index position of which headline to display
    QString ident = SpareList[n]; //reads from the index the headline into a string again.
    ui->plainTextEdit->setPlainText(ident); //Displays string in plaintext
    if(n==(SpareList.size()-2)){ //if reaching the last headline in list, index is reset to beginning again
        n=0;
    }
}




