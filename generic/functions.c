#include <stdio.h>

int max(int x, int y) 
{ 
    if (x > y) 
      return x; 
    else
      return y; 
}


// main function that doesn't receive any parameter and 
// returns integer. 
int main(void) 
{ 
    int a = 10, b = 20; 
  
    // Calling above function to find max of 'a' and 'b' 
    
	
	printf("Number a: ");
	scanf("%d", &a);
	printf("Number b: ");
	scanf("%d", &b);
	
	int m = max(a, b); 
    printf("max is %d", m); 
    return 0; 
} 
