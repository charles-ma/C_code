#include "csapp.h" 
#include "string.h"

int main(int argc, char **argv)
{
  //declare variables
  int clientfd, port; 
  char *host, buf[MAXLINE], *page, *temp_name, *modify; 
  rio_t rio; 

  //init parameters
  host = argv[1]; //host name
  port = atoi(argv[2]); //port number
  page = argv[3]; //file path

  //open socket
  clientfd = Open_clientfd(host, port);
  Rio_readinitb(&rio, clientfd); 

  //check temp
  temp_name = (char*) malloc(100 * sizeof(char));
  modify = (char*) malloc(100 * sizeof(char));
  strcat(temp_name, "./temp/");
  strcat(temp_name, host);
  strcat(temp_name, page + 1);
  
  FILE *temp_file = fopen(temp_name, "r");
  if(temp_file == NULL) { //temp file does not exist
    modify[0] = '\0';
  } else { //temp file exists
    char * line = (char*) malloc(1000 * sizeof(char));
    int * len = (int*) malloc(sizeof(int));
    while(getline(&line, len, temp_file) != -1) {
      if(strstr(line, "Last-Modified:") != NULL) {
	strcpy(modify, "If-Modified-Since: ");
	strcat(modify, line + 15);
	break;
      }
    }
    fclose(temp_file);
    free(line);
    free(len);
  }

  //construct request
  strcpy(buf, "GET ");
  strcat(buf, page);
  strcat(buf, " HTTP/1.1\r\nHost:");
  strcat(buf, host);
  strcat(buf, "\r\n");
  if(strlen(modify) != 0) strcat(buf, modify);
  strcat(buf, "\r\n");
  
  //send request
  Rio_writen(clientfd, buf, strlen(buf));

  //get response
  int conLen = 0;
  int body = 0;
  int count = 0;
  while (1) { 
    Rio_readlineb(&rio, buf, MAXLINE);
    
    //304 read local file
    if(strstr(buf, "304 Not Modified")) {
      temp_file = fopen(temp_name, "r");
      char * line = (char*) malloc(1000 * sizeof(char));
      int * len = (int*) malloc(sizeof(int));
      while(getline(&line, len, temp_file) != -1) {
	Fputs(line, stdout);
	fflush(stdout);
      }
      break;
    }

    //404 not found
    if(strstr(buf, "404 Not Found")) {
	Fputs(buf, stdout);
	Fputs("\n", stdout);
	fflush(stdout);
	break;
    }

    //read remote file
    if(count == 0) {
      //if(temp_file != NULL) fclose(temp_file);
      temp_file = fopen(temp_name, "w");
    }
    if(strstr(buf, "Content-Length") != NULL) {
      char conLenChar[100];
      strcpy(conLenChar, (buf + 16));
      conLen = atoi(conLenChar);
    }
    if(strlen(buf) == 2) body = 1;
    Fputs(buf, stdout); 
    fprintf(temp_file, "%s", buf);
    fflush(stdout);    
    if(body == 1) {
      conLen -= strlen(buf) * sizeof(char);
      if(conLen <= 0) {
	break;
      }
    }
    count++;
  } 

  //terminate the program
  close(clientfd); 
  if(temp_file != NULL) fclose(temp_file);
  exit(0); 
}
