#include<stdio.h>
#include "scheduler.h"

int main()
{
    int n;
    
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n];

    printf("Enter arrival times:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter burst times:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&bt[i]);

    int quantum;
    printf("Enter time quantum for Round Robin: ");
    scanf("%d",&quantum);

    float fcfs_avg, sjf_avg, rr_avg;

    fcfs(n,at,bt,&fcfs_avg);

    sjf(n,at,bt,&sjf_avg);

    roundRobin(n,at,bt,quantum,&rr_avg);

    printf("\n---- Comparison ----\n");

    printf("FCFS Avg Waiting Time = %.2f\n",fcfs_avg);
    printf("SJF Avg Waiting Time = %.2f\n",sjf_avg);
    printf("RR Avg Waiting Time = %.2f\n",rr_avg);

    if(fcfs_avg < sjf_avg && fcfs_avg < rr_avg)
        printf("Best Algorithm: FCFS\n");

    else if(sjf_avg < rr_avg)
        printf("Best Algorithm: SJF\n");

    else
        printf("Best Algorithm: Round Robin\n");

    return 0;
}
