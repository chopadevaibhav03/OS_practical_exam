// Q.1 Write a program to illustrate the concept of orphan process (Using fork() and sleep())

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    int pid;
    pid = fork();
    if (pid > 0 ){
        printf("parent process\n");
        printf("ID:%d\n\n",getpid());
    }else if (pid == 0)
    {
        printf("child process\n");
        printf("ID:%d\n\n",getpid());
        printf("parent ID:%d\n\n",getpid());
        sleep(10);
        printf("child process\n");
        printf("ID:%d\n\n",getpid());
        printf("parent ID:%d\n\n",getpid());
    }else{
        printf("faild to create child process:");
    }
    return 0;
    
}