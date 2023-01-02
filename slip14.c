// Q.1 Write a program to find the execution time taken for execution of a given set of instructions
// (use clock() function)

#include <stdio.h>
#include <time.h>
void main(){
    clock_t start,end;
    char name;
    start = clock();
    printf("timmer starts:\n");
    printf("\nEnetr your name:\n");
    scanf("%c\n",&name);
    printf("timmer ends:\n");
    end = clock();
    double time_taken = ((double)(end -start))/CLOCKS_PER_SEC;
    printf("the program takes time to execute is %f:\n",time_taken);
}