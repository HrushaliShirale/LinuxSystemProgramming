#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        if(stat(name,&sobj)==0)
        {
        if(S_ISREG(sobj.st_mode))
        {
            printf("Its a regular file\n");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
           printf("Its a directory\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Its a symbolic link\n");
        }
        }
    }

    closedir(dp);
    
    return 0;
}