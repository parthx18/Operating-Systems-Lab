/*Completion Time (CT): Time at which the process finishes execution.
Turnaround Time (TAT): $Total\ Time\ Spent = CT - Arrival\ Time
Waiting Time (WT): $Time\ Spent\ Waiting = TAT - Burst\ Time
C Program for FCFS*/
#include <stdio.h>

void findAverageTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], ct[n];
    int total_wt = 0, total_tat = 0;

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        // If process arrives after the previous one finishes
        if (at[i] > ct[i-1]) 
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    findAverageTime(processes, n, burst_time, arrival_time);
    return 0;
}
