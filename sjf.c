#include<stdio.h>
#include "scheduler.h"

void sjf(int n, int at[], int bt[], float *avg_wt)
{
    int ct[n], tat[n], wt[n];

    // simple sorting by burst time
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[i] > bt[j])
            {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];

    for(int i=1;i<n;i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    float total_wt = 0;

    printf("\n--- SJF ---\nGantt Chart:\n");

    printf("%d ", at[0]);

    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_wt += wt[i];

        printf("| P%d | %d ",i+1,ct[i]);
    }

    *avg_wt = total_wt / n;

    printf("\nAverage Waiting Time = %.2f\n",*avg_wt);
}
