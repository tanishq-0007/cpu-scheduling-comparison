#include<stdio.h>
#include "scheduler.h"

void roundRobin(int n, int at[], int bt[], int quantum, float *avg_wt)
{
    int remaining[n];
    int ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++)
        remaining[i] = bt[i];

    int time = 0;
    int completed = 0;

    float total_wt = 0;

    printf("\n--- Round Robin ---\nGantt Chart:\n");

    printf("0 ");

    while(completed < n)
    {
        for(int i=0;i<n;i++)
        {
            if(remaining[i] > 0)
            {
                if(remaining[i] > quantum)
                {
                    time += quantum;
                    remaining[i] -= quantum;
                }
                else
                {
                    time += remaining[i];
                    remaining[i] = 0;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    total_wt += wt[i];

                    completed++;
                }

                printf("| P%d | %d ",i+1,time);
            }
        }
    }

    *avg_wt = total_wt / n;

    printf("\nAverage Waiting Time = %.2f\n",*avg_wt);
}
