#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd=0;

    if(argc!=2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    fd= open(argv[1],O_RDWR | O_CREAT);

    if(fd != -1)
    {
        printf("File is opened with fd %d\n",fd);
    }
    else
    {
        printf("Unable to open file\n");
    }
    return 0;
}