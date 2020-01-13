#include <stdio.h>
int main() {
   int x[4];
   int i;
   for(i = 0; i < 4; ++i) {
      printf("&x[%d] = %p\n", i, &x[i]);
   }
   printf("Address of array x: %p", x);
   printf("\n");
   printf("Array with vals not aligned \n");
   for(i = 0; i < 4; ++i) {
      printf("x[%d] = %d\n", i, *(&x[i])  );
   }
   x[0] = 1; x[1] = 3; x[2] = 4; x[3] = 20;
   printf("Array with vals aligned \n");
   for(i = 0; i < 4; ++i) {
      printf("x[%d] = %d\n", i, *(&x[i])  );
   }
   return 0;
}
