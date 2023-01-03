#include <stdio.h>
#include <string.h>
int n, Bu[10], A[10], Twt, Ttt, wt[20], w;
float Awt, Att;
char pname[20][20], c[20][20];

void getdata()
{
    printf("Enter the number of process: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the process name: ");
        scanf("%s", &pname[i]);
        printf("Enter the Arrival time: ");
        scanf("%d", &A[i]);
        printf("Enter the Brust time: ");
        scanf("%d", &Bu[i]);
    }
}

void ganttChart()
{
    printf("\nGantt Chart\n");
    for (int i = 1; i <= n; i++)
        printf("  %s  |", pname[i]);
    printf("\n----------------------\n");
    printf(" ");
    for (int i = 1; i <= n; i++)
        printf("%d     ", wt[i]);
    printf("%d", wt[n] + Bu[n]);
}

void cal()
{
    wt[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        // compilation time
        wt[i] = Bu[i - 1] + wt[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        // total waiting time
        Twt += wt[i] - A[i];
        // Total TurnAround Time
        Ttt += (wt[i] + Bu[i] - A[i]);
    }
    printf("    processes\tBT\tAT\tWT\tTat\n");
    for (int i = 1; i <= n; i++)
    {
        printf("\t%s\t%d\t%d\t%d\t%d\n", pname[i], Bu[i], A[i], wt[i], (wt[i] + Bu[i]) - A[i]);
    }
    // Calculate the Average TurnAround Time and Waiting Time
    Att = (float)Ttt / n;
    Awt = (float)Twt / n;
    printf("\nAverage Turn around time : %3.2fms \n", Att);
    printf("\nAverage Waiting time : %3.2fms \n", Awt);
}

void fcfs()
{
    int temp, temp1;
    Twt = 0;
    Ttt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (A[i] > A[j])
            {
                temp = Bu[i];
                temp1 = A[i];
                Bu[i] = Bu[j];
                A[i] = A[j];
                Bu[j] = temp;
                A[j] = temp1;
                strcpy(c[i], pname[i]);
                strcpy(pname[i], pname[j]);
                strcpy(pname[j], c[i]);
            }
        }
    }

    cal();
    ganttChart();
}
int main()
{
    getdata();
    fcfs();
    return 0;
}
