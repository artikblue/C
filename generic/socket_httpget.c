#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h> 
#include <fcntl.h>
#include <stdlib.h>

#define BSIZE 256
#define KSIZE 11
// Lame sample routine for key extraction from an http response
void getKey(char buf[], char key[]){
    int i = 0;
    int kg = 0;
    int ki = 0;

    while(i < BSIZE && kg == 0){
        if(buf[i]== '<' && buf[i+1] == 'k' && buf[i+2] == '>' ){

            for(int j=i+3; j < KSIZE+i+2; j++){
                key[ki] = buf[j];
                ki = ki+1;
            }
            kg = 1;
        }
        i = i+1;
    }
}
// Lame sample routine for byte array xor
void cryp(char key[], char buf[]){

    for(int i = 0; i < KSIZE; i ++){
        buf[i] ^= key[i];
    }

}
// open a file xor the content and dump it to another file
void crypFile(char file[], char key[]){

    int infile, outfile; 
    char buff[KSIZE];
    infile = open (file, O_RDONLY , 0644); 
    outfile = open ("crypted.cry", O_WRONLY | O_CREAT, 0644);
    while(read(infile, &buff, KSIZE)){ 
        cryp(key, buff);

        write(outfile, &buff, KSIZE);
    }
    close (infile); 
    close (outfile);

}

int main(int argc, char *argv[]) {
   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;
   char key[KSIZE];
   char request[] = "GET /key.txt HTTP/1.1\r\nUser-Agent: nc/0.0.1\r\nHost: 127.0.0.1\r\nAccept: */*\r\n\r\n";
   char buffer[BSIZE];

   portno = 80;
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   server = gethostbyname("127.0.0.1");

   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);

   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      exit(1);
   }

   bzero(buffer,BSIZE);

   n = write(sockfd, request, strlen(request));

   bzero(buffer,BSIZE);
   n = read(sockfd, buffer, BSIZE);
   getKey(buffer, key);

   crypFile("sample.txt",key);
   return 0;
}

