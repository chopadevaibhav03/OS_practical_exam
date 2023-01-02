// Q. 1 Creating a child process using the command exec(). Note down process ids of the parent
// and the child processes, check whether the control is given back to the parent after the child
// process terminates.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    printf("\n PID of slip3.c if:%d",getpid());
    char*args[] = {NULL};
    execv("Hello",args);
    printf("\n Back to slip3.c");
    return 0;
}