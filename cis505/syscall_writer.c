/* syscall_writer.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define OUTPUTNAME "write.out"
main()
{
	long i;
	int fd;

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
	exit(0);
}
