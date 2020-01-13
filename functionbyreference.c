#include <stdio.h>
void addone(int * n) {
    (*n)++;
}
int main() {

int n;
printf("Before: %d\n", n);
addone(&n);
printf("After: %d\n", n);
  return 0;
}
