#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define OUTPUTNAME "write.out"
#define YETOUTPUTNAME "fprint.out"

pthread_mutex_t lock;

void *system_call(void* s) {
  long i;
  int fd;
  char* tmp = (char*) s;
  
  if ((fd=open(OUTPUTNAME,O_WRONLY|O_CREAT,0644)) <  0) {
    fprintf(stderr,"Can't open %s.  Bye.\n",OUTPUTNAME);
    exit(1);
  }
  for (i=0; i<50000; i++)  { /* write 50,000 Ys with write */
    if (write(fd,"Y",1) < 1) {
      fprintf(stderr,"Can't write. Bye\n");
      exit(1);
    }
  }
  close(fd);
  pthread_mutex_lock(&lock);  
  strcpy(tmp, "stdlibrary call thread finished first!\n");
  pthread_mutex_unlock(&lock);  
}

void *stdlibrary_call(void* s) {
  long i;
  FILE *fp;
  
  if ((fp=fopen(YETOUTPUTNAME,"w")) == NULL) {
    fprintf(stderr,"Can't open %s.  Bye.\n",YETOUTPUTNAME);
    exit(1);
  }
  for (i=0; i<400000; i++) {  /* write 400,000 Xs with fprintf */
    if (fprintf(fp,"X") < 1) {
      fprintf(stderr,"Can't write. Bye\n");
      exit(1);
    }
  }
  fclose(fp);
  pthread_mutex_lock(&lock);  
  strcpy(s, "system call thread finished first!\n");
  pthread_mutex_unlock(&lock);  
}

main() {
  pthread_t thread1, thread2;
  int ret1, ret2;
  char result[100];
  
  if (pthread_mutex_init(&lock, NULL) != 0) {
    printf("\n mutex init failed\n");
    return 1;
  }
  
  ret1 = pthread_create(&thread1, NULL, system_call, (void*) result);
  ret2 = pthread_create(&thread2, NULL, stdlibrary_call, (void*) result);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("%s", &result);
  exit(0);
}
