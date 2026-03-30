#ifndef SCHEDULER_H
#define SCHEDULER_H

void fcfs(int n, int at[], int bt[], float *avg_wt, float *avg_tat);
void sjf(int n, int at[], int bt[], float *avg_wt, float *avg_tat);
void roundRobin(int n, int at[], int bt[], int quantum, float *avg_wt, float *avg_tat);

#endif
