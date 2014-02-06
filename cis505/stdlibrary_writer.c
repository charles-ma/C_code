/* stdlibrary_writer.c */
#include <stdio.h>
#define OUTPUTNAME "fprint.out"
main()
{
	long i;
	FILE *fp;
	
	if ((fp=fopen(OUTPUTNAME,"w")) == NULL) {
		fprintf(stderr,"Can't open %s.  Bye.\n",OUTPUTNAME);
		exit(1);
	}
	for (i=0; i<400000; i++) {  /* write 400,000 Xs with fprintf */
		if (fprintf(fp,"X") < 1) {
			fprintf(stderr,"Can't write. Bye\n");
			exit(1);
		}
	}
	fclose(fp);
	exit(0);
}
