#include <stdio.h>
#include "scheduler.h"

void fcfs(int n, int at[], int bt[], float *avg_wt, float *avg_tat){

    int wt[n], tat[n];

    wt[0] = 0;

    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    float total_wt = 0;
    float total_tat = 0;

    printf("Gantt Chart:\n0 ");

    for(int i=0;i<n;i++){

        printf("| P%d | %d ", i+1, wt[i]+bt[i]);

        tat[i] = wt[i] + bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    *avg_wt = total_wt / n;
    *avg_tat = total_tat / n;

    printf("\nAverage Waiting Time = %.2f\n", *avg_wt);
    printf("Average Turnaround Time = %.2f\n", *avg_tat);
}
