// Q.1 Write the program to calculate minimum number of resources needed to avoid deadlock.
#include <stdio.h>
int main()
{
    int max[10][10], need[10][10], alloc[10][10];
    int p, r, i, j;

    printf("Enter the number of processes and resources : ");
    scanf("%d %d", &p, &r);

    printf("Enter the max matrix elements");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d ", &max[i][j]);

    printf("max matrix elements are \n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("Enter the Allocation matrix elements ");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    printf("\n");

    printf("Allocation matrix elements are\n ");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\n");
    }

    printf("Need Mattrix : \n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
    return 0;
}
