#include <stdio.h>
#include "scheduler.h"

void roundRobin(int n, int at[], int bt[], int quantum, float *avg_wt) {
    int rt[n], wt[n], time = 0, completed = 0;

    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
        wt[i] = 0;
    }

    while (completed < n) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 0;

                if (rt[i] > quantum) {
                    time += quantum;
                    rt[i] -= quantum;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i] - at[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if (done)
            time++;
    }

    float total_wt = 0;
    for (int i = 0; i < n; i++)
        total_wt += wt[i];

    *avg_wt = total_wt / n;
}
