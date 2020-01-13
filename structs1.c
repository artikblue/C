#include<stdio.h> 
#include <string.h>    
struct Point 
{ 
   int x, y; 
}; 

struct Person 
{ 
   int age;
   char * name;
}; 
  
int main() 
{ 
   // Create an array of structures  char * name = "johndoe";
   struct Point arr[10]; 
   struct Person parr[2];
   parr[0].name = "Alfred";
   parr[0].age = 34;
   
   parr[1].name = "Joseph";
   parr[1].age = 43;
    
   // Access array members 
   arr[0].x = 10; 
   arr[0].y = 20; 
  
   printf("%d %d", arr[0].x, arr[0].y);
   printf("%s %d", parr[1].name, parr[1].age);
   return 0; 
} 
