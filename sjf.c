#include<stdio.h>
#include "scheduler.h"

void sjf(int n, int at[], int bt[], float *avg_wt)
{
    int ct[n], tat[n], wt[n];
    int completed[n];

    for(int i=0;i<n;i++)
        completed[i] = 0;

    int time = 0, done = 0;
    float total_wt = 0;

    printf("\n--- SJF ---\nGantt Chart:\n");

    while(done < n)
    {
        int shortest = -1;

        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && completed[i]==0)
            {
                if(shortest == -1 || bt[i] < bt[shortest])
                    shortest = i;
            }
        }

        if(shortest == -1)
        {
            time++;
            continue;
        }

        printf("%d | P%d | ",time,shortest+1);

        time += bt[shortest];

        ct[shortest] = time;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        total_wt += wt[shortest];

        completed[shortest] = 1;
        done++;
    }

    printf("%d",time);

    *avg_wt = total_wt/n;

    printf("\nAverage Waiting Time = %.2f\n",*avg_wt);
}
