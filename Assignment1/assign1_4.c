#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int fd=0;

    if(argc!=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fstat (argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open the file\n");
        return -1;
    }

    fstat(fd,&sobj);

    printf("Name of the file is : %s\n",argv[1]);
    printf("File size is : %d\n",sobj.st_size);
    printf("Number of Links : %d\n",sobj.st_nlink);
    printf("Inode number is : %d\n",sobj.st_ino);
    printf("File system number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);
    
    close(fd);

    return 0;
}