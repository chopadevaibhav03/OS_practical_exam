// Q.1 Write a program to create a child process using fork().The parent should goto sleep state and
// child process should begin its execution. In the child process, use execl() to execute the “ls” command. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    int pid;
    printf("hello world (pid:%d)\n",getpid());
    int rc = fork();
    if(rc == 0){
        printf("Hello,I am child:(pid:%d)\n",getpid());
        excel("/bin/ls","ls",NULL);
    }else{
        sleep(3);
        printf("\nI am parent is %d :(pid:%d)",getpid());
    }
    return 0;
}

// #include <stdio.h>
// #include <unistd.h>

// int main() {
//    int pid = fork();
//    if (pid == 0) {
//       // This is the child process
//       execl("/bin/ls", "ls", NULL);
//    } else {
//       // This is the parent process
//       sleep(10);
//    }
//    return 0;
// }