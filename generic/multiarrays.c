#include <stdio.h>
 
int main () {

   /* an array with 5 rows and 2 columns*/
   int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
   int i, j;
 
   /* output each array element's value */
   for ( i = 0; i < 5; i++ ) {

      for ( j = 0; j < 2; j++ ) {
         printf("a[%d][%d] = %d\n", i,j, a[i][j] );
      }
   }
   
   
   // more dimensions
   
   
      /* an array with 5 rows and 2 columns*/
   int a2[5][3] = { {0,0,3}, {1,2,6}, {2,4,9}, {3,6,1},{4,8,2}};
   int i2, j2;
 
   /* output each array element's value */
   for ( i2 = 0; i2 < 5; i2++ ) {

      for ( j2 = 0; j2 < 2; j2++ ) {
         printf("a[%d][%d] = %d\n", i2,j2, a2[i2][j2] );
      }
   }
   return 0;
}
