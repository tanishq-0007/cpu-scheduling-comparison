#include <stdio.h>
#include "scheduler.h"

void sjf(int n, int at[], int bt[], float *avg_wt, float *avg_tat){

    int wt[n], tat[n];
    int completed[n];

    for(int i=0;i<n;i++)
        completed[i]=0;

    int time = 0, done = 0;

    float total_wt = 0;
    float total_tat = 0;

    printf("Gantt Chart:\n");

    while(done < n){

        int min_bt = 9999;
        int index = -1;

        for(int i=0;i<n;i++){
            if(at[i] <= time && completed[i]==0){
                if(bt[i] < min_bt){
                    min_bt = bt[i];
                    index = i;
                }
            }
        }

        if(index != -1){

            wt[index] = time - at[index];

            if(wt[index] < 0)
                wt[index] = 0;

            printf("%d | P%d | ", time, index+1);

            time += bt[index];

            tat[index] = wt[index] + bt[index];

            total_wt += wt[index];
            total_tat += tat[index];

            completed[index] = 1;

            done++;
        }
        else{
            time++;
        }
    }

    printf("%d\n", time);

    *avg_wt = total_wt / n;
    *avg_tat = total_tat / n;

    printf("Average Waiting Time = %.2f\n", *avg_wt);
    printf("Average Turnaround Time = %.2f\n", *avg_tat);
}
