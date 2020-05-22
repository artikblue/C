// C program to illustrate strings 
  
#include <stdio.h> 
#include <string.h>  
int main() 
{    
    // declare and initialize string 
    char welcome[] = "Enter your name: \n"; 
      
    // print string 
    printf("%s",welcome); 
    
    char str[50]; 
      
    // reading string 
    scanf("%s",str); 
    
    char * name = "johndoe";

	if (strcmp(str, name) == 0) {
		printf("Hello, John!\n");
	} else {
		printf("You are not John. Go away.\n");
	}
      
    return 0; 
} 
