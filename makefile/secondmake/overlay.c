#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   int choice = 0;

// A process can change it own program
   printf("The process will be overlaid.\n");
   printf("Choose process 1 (type 1) or process 2 (type 2)\n");
   scanf("%d",&choice);
   putchar('\n');
   if(choice == 1)
	if (execl("pgm1","pgm1","a","b","c",0) == -1) {
                perror("Exec failed");
                exit(EXIT_FAILURE);
        }

   if(choice == 2)
	if (execl("pgm2","pgm2","1","2","3","4",0) == -1) {
                perror("Exec failed");
                exit(EXIT_FAILURE);
        }
   printf("ERROR:  You did not input 1 or 2\n");
   
   exit(0);
}