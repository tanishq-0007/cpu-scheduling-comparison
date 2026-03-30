#include <stdio.h>
#include "scheduler.h"

void roundRobin(int n, int at[], int bt[], int quantum, float *avg_wt, float *avg_tat){

    int rem_bt[n], wt[n], tat[n];

    for(int i=0;i<n;i++){
        rem_bt[i] = bt[i];
        wt[i] = 0;
    }

    int time = 0;

    printf("Gantt Chart:\n0 ");

    int done;

    do{

        done = 1;

        for(int i=0;i<n;i++){

            if(rem_bt[i] > 0){

                done = 0;

                printf("| P%d | ", i+1);

                if(rem_bt[i] > quantum){

                    time += quantum;

                    rem_bt[i] -= quantum;
                }
                else{

                    time += rem_bt[i];

                    wt[i] = time - bt[i];

                    rem_bt[i] = 0;
                }

                printf("%d ", time);
            }
        }

    }while(done == 0);

    float total_wt = 0;
    float total_tat = 0;

    for(int i=0;i<n;i++){

        tat[i] = wt[i] + bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    *avg_wt = total_wt / n;
    *avg_tat = total_tat / n;

    printf("\nAverage Waiting Time = %.2f\n", *avg_wt);
    printf("Average Turnaround Time = %.2f\n", *avg_tat);
}
