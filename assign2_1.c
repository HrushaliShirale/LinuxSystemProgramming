#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    Ret = read(fd,Buffer,sizeof(Buffer));  

    printf("Data from file is : %s\n",Buffer); 
     
    close(fd);

    return 0;
}