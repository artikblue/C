#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
int main()
{
    printf("Hello world!\n");

    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    char base_path[30] = "C:\\samples\\stor\\";
    hFind = FindFirstFile("C:\\samples\\stor\\*.txt",&FindFileData);
    printf("Search handler = %d \n", hFind);


    while(hFind != ERROR_NO_MORE_FILES){
        strcat(base_path,FindFileData.cFileName);
        printf("Name= %s \n",base_path );

        hFind = FindNextFile(hFind,&FindFileData);
    }



    return 0;
}

