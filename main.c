#include <stdio.h>
#include "scheduler.h"

int main() {
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];

    printf("Enter arrival times:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter burst times:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&bt[i]);

    printf("Enter time quantum for Round Robin: ");
    scanf("%d",&quantum);

    printf("\nProcess Table\n");
    printf("Process\tArrival\tBurst\n");

    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\n", i+1, at[i], bt[i]);
    }

    float avg_wt_fcfs, avg_wt_sjf, avg_wt_rr;
    float avg_tat_fcfs, avg_tat_sjf, avg_tat_rr;

    printf("\n--- FCFS ---\n");
    fcfs(n, at, bt, &avg_wt_fcfs, &avg_tat_fcfs);

    printf("\n--- SJF ---\n");
    sjf(n, at, bt, &avg_wt_sjf, &avg_tat_sjf);

    printf("\n--- Round Robin ---\n");
    roundRobin(n, at, bt, quantum, &avg_wt_rr, &avg_tat_rr);

    printf("\n---- Comparison ----\n");

    printf("FCFS Avg Waiting Time = %.2f\n", avg_wt_fcfs);
    printf("FCFS Avg Turnaround Time = %.2f\n\n", avg_tat_fcfs);

    printf("SJF Avg Waiting Time = %.2f\n", avg_wt_sjf);
    printf("SJF Avg Turnaround Time = %.2f\n\n", avg_tat_sjf);

    printf("RR Avg Waiting Time = %.2f\n", avg_wt_rr);
    printf("RR Avg Turnaround Time = %.2f\n\n", avg_tat_rr);

    float best = avg_wt_fcfs;
    char algo[20] = "FCFS";

    if(avg_wt_sjf < best){
        best = avg_wt_sjf;
        sprintf(algo,"SJF");
    }

    if(avg_wt_rr < best){
        best = avg_wt_rr;
        sprintf(algo,"Round Robin");
    }

    printf("Best Algorithm: %s\n", algo);

    return 0;
}
