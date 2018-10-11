#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
   int i, sum = 0, value;

   for (i=0; i<argc; ++i)       /* sum the argument list */
        if((sscanf(argv[i],"%d",&value))==1)
           sum += value;

   printf("%s:  sum of command line arguments = %d\n",argv[0],sum);
   exit(0);
}