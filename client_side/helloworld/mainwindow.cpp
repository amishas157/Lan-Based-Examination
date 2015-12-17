#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test.h"
#include "arpa/inet.h"
#include <sys/socket.h>
#include <sys/types.h>
#include "fstream"

#include "sys/types.h"
#include "netinet/in.h"
#include "netdb.h"
#include "stdio.h"
#include <unistd.h>


#include "sys/stat.h"

using std::ofstream;
using std::ifstream;
using std::string ;

ofstream file_recv;

char *server_address;
int portno;

//function to print the error message
void error(char *msg)
{
    perror(msg);
    exit(0);
}

MainWindow::MainWindow(char *address, int port, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //fetching the server address and the port number for connection
    ui->setupUi(this);
    server_address = address;
    portno = port;
    file_recv.open("client_questions.txt",ofstream::trunc);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    //start the test when the start test button is clicked
    int sockfd, n;



    //creating the socket
    struct sockaddr_in serv_addr;
    struct hostent *server;


    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);


    if (sockfd < 0)
        error("ERROR opening socket");

   //server = gethostbyname("192.168.43.15");
   // serv_addr.sin_addr.s_addr = inet_addr("192.168.43.15");

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET,server_address,&serv_addr.sin_addr);

    if (::connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    //recieveing the question paper from the server
    recv(sockfd, buffer, 1024, 0);
    file_recv<<buffer;


    file_recv.close();

    Test *x = new Test(sockfd);


    this->close();
    //display the test form
    x->show();

}
