#include "csapp.h" 
#include "string.h"

int main(int argc, char **argv)
{
  //declare variables
  int clientfd, port; 
  char *host, buf[MAXLINE], *page; 
  rio_t rio; 

  //init parameters
  host = argv[1]; //host name
  port = atoi(argv[2]); //port number
  page = argv[3]; //file path

  //open socket
  clientfd = Open_clientfd(host, port);
  Rio_readinitb(&rio, clientfd); 

  //construct request
  strcat(buf, "GET ");
  strcat(buf, page);
  strcat(buf, " HTTP/1.1\r\nHost:");
  strcat(buf, host);
  strcat(buf, "\r\n\r\n");

  //send request
  Rio_writen(clientfd, buf, strlen(buf));

  //get response
  int conLen = 0;
  int body = 0;
  while (1) { 
    Rio_readlineb(&rio, buf, MAXLINE); 
    if(strstr(buf, "Content-Length") != NULL) {
      char conLenChar[100];
      strcpy(conLenChar, (buf + 16));
      conLen = atoi(conLenChar);
    }
    if(strlen(buf) == 2) body = 1;
    Fputs(buf, stdout); 
    fflush(stdout);    
    if(body == 1) {
      conLen -= strlen(buf) * sizeof(char);
      if(conLen <= 0) break;
    }
  } 

  //terminate the program
  close(clientfd); 
  exit(0); 
} 
