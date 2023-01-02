// Q.1 Create a child process using fork(), display parent and child process id. Child process will
// display the message “Hello World” and the parent process should display “Hi”


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    int pid;
    pid = fork();
    if(pid > 0){
        printf("erroe in creation of child process:\n");
        exit(1);
    }else if (pid == 0)
    {
        printf("hello world,I am child process:\n");
        printf("child pid %d",getpid());
        exit(0);
    }else{
        printf("\n hi , iam parent process\n");
        printf("parent pid is %d",getpid());
        exit(1);
    }
    
}