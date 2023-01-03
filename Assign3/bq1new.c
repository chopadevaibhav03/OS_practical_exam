#include <stdio.h>
#include <string.h>
int main()
{
    int num, i, j, n, m, Need[10][10], avail[10], max[10][10], alloc[10][10];
    printf("Enter the number of processes and resources:");
    scanf("%d%d", &i, &j);
    printf("Enter the elements for alloc martrix:");
    for (n = 0; n < i; n++)
        for (m = 0; m < j; m++)
            scanf("%d", &alloc[n][m]);
    printf("Enter the elements for max matrix:");
    for (n = 0; n < i; n++)
        for (m = 0; m < j; m++)
            scanf("%d", &max[n][m]);
    do
    {
        printf("Enter a case(1,2,3,4) / or 0 to exit :");
        scanf("%d", &num);
        switch (num)
        {

        case 1:
            printf("Enter available resources:");
            for (m = 0; m < j; m++)
                scanf("%d", &avail[m]);
            break;
        case 2:
            printf("\nAllocation Matrix\n");
            for (n = 0; n < i; n++)
            {
                for (m = 0; m < j; m++)
                {
                    printf("%d\t", alloc[n][m]);
                }
                printf("\n");
            }
            printf("Max Matrix\n");
            for (n = 0; n < i; n++)
            {
                for (m = 0; m < j; m++)
                {
                    printf("%d\t", max[n][m]);
                }
                printf("\n");
            }
            break;
        case 3:
            printf("\nNeed content Matrix\n");
            for (n = 0; n < i; n++)
            {
                for (m = 0; m < j; m++)
                {
                    Need[n][m] = max[n][m] - alloc[n][m];
                    printf("%d\t", Need[n][m]);
                }
                printf("\n");
            }
            break;
        case 4:
            printf("\n");
            for (m = 0; m < j; m++)
            {
                printf("%d\t", avail[m]);
            }
            printf("\n");
            break;

        default:
            printf("\nExit\n");
        }
    } while (num != 0);
    return 0;
}
