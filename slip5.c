// Q.1 Write a program that demonstrates the use of nice () system call. After a child process is
// started using fork (), assign higher priority to the child using nice () system call.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    int pid,retnice;
    pid = fork();
    {
        if(pid == 0){
            retnice = nice(-1);
            printf("child gets heigher priority:\n",retnice);
            sleep(1);
        }
        else{
            retnice = nice(5);
            printf("parent gets heigher priority:\n",retnice);
            sleep(1);
        }
    }
    return 0;
}