//Q.1 Write a program to create a child process using fork().The parent should goto sleep state and
// child process should begin its execution. In the child process, use execl() to execute the “ls” command.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    int pid;
    printf("Hello:(pid:%d)\n",getpid());
    int rc = fork();
    if(rc == 0){
        printf("hello  ,i am child:(pid:%d)\n",getpid());
        execl("/bin/lc","ls",NULL);
    }else{
        sleep(3);
        printf("i am parent process %d:(pid:%d)",getpid());
    }
    return 0;
}