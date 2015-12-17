#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

using std::ifstream;
using std::string ;

    ifstream infile;

void dostuff(int); /* function prototype */

/* function to print out the error messages */
void error(char *msg)
{
    perror(msg);
    exit(1);
}

/* main function of the server where the socket is made and establishes connection with the client */


int main(int argc, char *argv[])
{
     // socket variables and supporting structures
     int sockfd, newsockfd, portno, clilen, pid;
     struct sockaddr_in serv_addr, cli_addr;

	 // creating the socket
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error((char*)"ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     //serv_addr.sin_addr.s_addr = inet_addr("10.100.91.1");
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error((char*)"ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     
	 // forking to handle multiple client requests and connections
	 while (1) {
         newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,  (socklen_t*) &clilen);
         if (newsockfd < 0) 
             error((char*)"ERROR on accept");
         pid = fork();
         if (pid < 0)
             error((char*)"ERROR on fork");
         if (pid == 0)  {
             close(sockfd);
             dostuff(newsockfd);
             exit(0);
         }
         else close(newsockfd);
     } /* end of while */
     return 0; /* we never get here */
}

/******** DOSTUFF() *********************
 There is a separate instance of this function 
 for each connection.  It handles all communication
 once a connection has been established.
 *****************************************/







void dostuff (int sock)
{
   // opening the file that is to be sent to the client
   int n;
   infile.open("server_file.txt");
   char buffer1[1024];
   char buffer[1024];
             bzero(buffer,1024);
             bzero(buffer1,1024);
	// writing the contents of the file in the buffer 		 
	while (!infile.eof())
            {
             infile.getline(buffer1,1024);
             strcat(buffer,buffer1);
             if(!infile.eof())
             strcat(buffer,"\n");
            }
//printf("%s",buffer);
			// sending the buffer to the client which has the information of the question paper.
             send(sock,buffer,sizeof(buffer), 0);


    infile.close();
	
	//the correct answers of the corresponding questions  
     char ans_array[10];
     ans_array[0]='a';
     ans_array[1]='a';
     ans_array[2]='a';
     ans_array[3]='a';
     ans_array[4]='a';
     ans_array[5]='a';
     ans_array[6]='a';
     ans_array[7]='a';
     ans_array[8]='a';
     ans_array[9]='a';

     char buff[1024];
     bzero(buff,1024);
	 

   //reading the answer file from the client to evaluate the score	 
   n = read(sock,buff,1024);
   
   // calculates the score of the client by comparing with the correct answers
   if (n > 0)
    {

     char score[1];
     bzero(score,1);
     
     int score_point =0;
      for(int i=0;i<10;i++)
       {
         if(ans_array[i] == buff[i])
          score_point++;
       }

	   
     score[0] = score_point;

    //sends the final score after evaluation back to the client 
     write(sock,score,sizeof(score));
    }
  

}

