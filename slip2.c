// Q.1 Create a child process using fork(), display parent and child process id. Child process will
// display the message “Hello World” and the parent process should display “Hi”.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int pid;
    pid = fork();

    if (pid < 0){
        printf("Error in creation of child process\n");
        exit(1);
    }else if (pid == 0)
    {
       printf("Hello World ,I am child process:\n");
       printf("child pid is %d\n",getpid());
       exit(0);
    }
    else
    {
        printf("Hii , i am parent process:\n");
        printf("parent pid id %d:\n",getpid());
        exit(1);
    }
}