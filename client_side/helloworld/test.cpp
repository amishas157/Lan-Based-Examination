#include "test.h"
#include "ui_test.h"
#include "fstream"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arpa/inet.h"
#include <sys/socket.h>
#include <sys/types.h>

#include "netinet/in.h"
#include "netdb.h"
#include "stdio.h"
#include <unistd.h>

#include "sys/stat.h"
#include "result.h"
#include <QTime>
#include <QTimer>
#include <QtCore>
#include "string";

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::string ;
int sock;
ifstream infile , ans_file;
ofstream outfile;

// Creating the timer
QTimer *timer ;

void set_question(Ui::Test);


Test::Test(int a, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test)
{

     ui->setupUi(this);
     sock = a;
     //reading the input question file
     infile.open("client_questions.txt",fstream::in);
     outfile.open("client_ans.txt",fstream::out);


     // initialize the timer
     timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));
     //timer counts after every 1s
     timer->start(1000);

     if(!infile.eof())

     //calling the function set_question to display the question on the form
     set_question(*ui);

}

Test::~Test()
{
    delete ui;
}


//method to support the timer function
//MySlot() is called after every second passes from the timer
void Test::MySlot()
{
    //initializing the maximum time alloted to the client
    static int x = 120;

    //display the remaining time
    if(x > 0)
    {
        x--;
        ui->label_2->setNum(x);
    }
    else
    {
        //automatically click the submit button when the time is over and also store the last marked answer

        if((*this->ui).option1->isChecked())
            outfile << "a";
        else if((*this->ui).option2->isChecked())
            outfile << "b";
        else if((*this->ui).option3->isChecked())
            outfile << "c";
        else if((*this->ui).option4->isChecked())
            outfile << "d";
        else
            outfile << "n";
        ui->pushButton_2->click();
       timer->stop();
    }


}

// displays the question by reading the question file sent by the seerver
void set_question(Ui::Test ui)
{
    char str[100];

    //display the question
    infile.getline(str,100);
    ui.label->setText(str);

    //display option1
    infile.getline(str,100);
    ui.option1->setText(str);

    //display option 2
    infile.getline(str,100);
    ui.option2->setText(str);

    //display option 3
    infile.getline(str,100);
    ui.option3->setText(str);

    //display option 4
    infile.getline(str,100);
    ui.option4->setText(str);


    //hide the next button for the last question
    if(infile.eof())
    {
        ui.pushButton->hide();
    }
}


// display next question when next button is clicked and store the answer
void Test::on_pushButton_clicked()
{
    //storing the answer of this question
    if((*this->ui).option1->isChecked())
        outfile << "a";
    else if((*this->ui).option2->isChecked())
        outfile << "b";
    else if((*this->ui).option3->isChecked())
        outfile << "c";
    else if((*this->ui).option4->isChecked())
        outfile << "d";
    else
        outfile << "n";

//display the next question
if(!infile.eof())
set_question(*this->ui);

}


//submits the answers of the test
void Test::on_pushButton_2_clicked()
{
    //storing the answer of the present question

        if((*this->ui).option1->isChecked())
            outfile << "a";
        else if((*this->ui).option2->isChecked())
            outfile << "b";
        else if((*this->ui).option3->isChecked())
            outfile << "c";
        else if((*this->ui).option4->isChecked())
            outfile << "d";
        else
            outfile << "n";

 outfile.close();
 //close the answer file
 ans_file.open("client_ans.txt",fstream::in);
 char buffer[1024];
 bzero(buffer,1024);
 ans_file.getline(buffer,1024);
 char score[1];

 //writing the answer file back to the server for checking
 write(sock,buffer,sizeof(buffer));
 bzero(score,sizeof(score));

 //reading the score from the server after evaluation
 read(sock, score, sizeof(score));
 result *res = new result(score[0]);
 this->close();
 res->show();
}
