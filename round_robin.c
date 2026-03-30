#include <stdio.h>
#include "scheduler.h"

void round_robin(Process p[], int n, int time_quantum) {
    int remaining[n];
    int waiting_time[n], turnaround_time[n];
    int time = 0, done;

    // Initialize remaining burst times
    for (int i = 0; i < n; i++) {
        remaining[i] = p[i].burst_time;
        waiting_time[i] = 0;
    }

    do {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;

                if (remaining[i] > time_quantum) {
                    time += time_quantum;
                    remaining[i] -= time_quantum;
                } else {
                    time += remaining[i];
                    waiting_time[i] = time - p[i].burst_time;
                    remaining[i] = 0;
                }
            }
        }
    } while (!done);

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = p[i].burst_time + waiting_time[i];
    }

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               p[i].pid,
               p[i].burst_time,
               waiting_time[i],
               turnaround_time[i]);
    }
}
