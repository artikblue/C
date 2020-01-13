#include <stdio.h>
 
int main () {
	int a = 0;
	int b = 43;

   /* while loop execution */
   while( a != b ) {
	  printf("Guess the number (a) \n");
	  scanf("%d", &a);

   }
   printf("Yeah!!");
   printf("Yes, value of b: %d\n", b);
 
   return 0;
}
