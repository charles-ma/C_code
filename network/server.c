#include "csapp.h"
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

FILE * log_file;

/*
 * Do actual work for each thread
 */
void *do_work(void* pconnfd)  
{ 
  size_t n;  
  char buf[MAXLINE];  
  rio_t rio; 
  int *connfd = (int*) pconnfd;
  char *page = (char*) malloc(100 * sizeof(char));
 
  //parse http requests
  Rio_readinitb(&rio, *connfd); 
  while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) { 
    //print server action
    printf("server received %d bytes\n", n);
    fprintf(log_file, "server received %d bytes\n", n);
    fflush(log_file);
    //parse GET
    if(strstr(buf, "GET")) {
      char * token = strtok(buf, " ");
      int i = 0;
      while(token != NULL) {
	token = strtok(NULL, " ");
	if(i == 0) strcpy(page, token);
	i++;
      }
    }

    //end of the request
    if(strcmp(buf, "\r\n") == 0) break;
  } 

  //produce http response
  FILE * fp;
  fp = fopen(page + 1, "r");
  if(fp == NULL) {
    Rio_writen(*connfd, "HTTP/1.1 404 NOT FOUND\r\n", 22);
  } else {
    //produce response header
    int *size = (int*) malloc(sizeof(int));
    char *response = (char*) malloc(1000 * sizeof(char));
    struct stat sb;
    stat(page + 1, &sb);
    char c_length[100];
    sprintf(c_length, "%d", (int)sb.st_size);
    Rio_writen(*connfd, "HTTP/1.1 200 OK\r\nServer: MaChaoServer\r\nContent-Length: ", 55);
    Rio_writen(*connfd, c_length, strlen(c_length));
    Rio_writen(*connfd, "\r\nContent-Type: text/html\r\n\r\n", 29);
    
    //produce response body
    while((n = getline(&response, size, fp)) != -1) {
      Rio_writen(*connfd, response, strlen(response));    
    }
  }

  //end the response routine
  Close(*connfd);
  free(connfd);
} 

/*
 * Create worker threads
 */
void create_worker(int connfd) {
  pthread_t *p = (pthread_t*) malloc(sizeof(pthread_t));
  int *pconnfd = (int*) malloc(sizeof(int));
  *pconnfd = connfd;
  pthread_create(p, NULL, do_work, pconnfd);
  free(p);
}

/*
 * Program entrance
 */
int main(int argc, char **argv) {
  int listenfd, connfd, port, clientlen;
  struct sockaddr_in clientaddr;
  struct hostent *hp;
  char *haddrp;

  //port number from command line
  port = atoi(argv[1]); 

  //open port
  listenfd = open_listenfd(port); 

  //open log file
  log_file = fopen("server_log.txt", "a");
  
  //main loop
  while (1) {
    clientlen = sizeof(clientaddr); 
    connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
    hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
		       sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    haddrp = inet_ntoa(clientaddr.sin_addr);
    printf("server connected to %s (%s)\n", hp->h_name, haddrp);
    fprintf(log_file, "server connected to %s (%s)\n", hp->h_name, haddrp);
    fflush(log_file);
    create_worker(connfd);
  }

  fclose(log_file);
}

