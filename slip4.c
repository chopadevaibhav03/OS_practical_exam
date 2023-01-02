// Q.1 Write a program to illustrate the concept of orphan process ( Using fork() and sleep())

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    int pid;
    pid = fork();

    if(pid > 0){
        printf("parent process\n ");
        printf("ID:%d\n",getpid());
    }else if (pid == 0)
    {
        printf("child process:\n");
        printf("ID - %d\n",getpid());
        printf("parent ID is %d\n",getpid());
        sleep(10);
        printf("child process:\n");
        printf("ID - %d\n",getpid());
        printf("parent ID is %d\n",getpid());
    }else{
        printf("faild to creat child process:");
    }
    return 0;
}