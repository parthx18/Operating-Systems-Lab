//These two algorithms are often confused, but the key difference is preemption. SJF (Shortest Job First) is usually non-preemptive (it waits for a process to finish), while SRTF (Shortest Remaining Time First) is the preemptive version of SJF.

//1. Shortest Job First (SJF) - Non-Preemptive
//In this version, once a process starts, it runs to completion. The CPU then looks at the ready queue and picks the process with the shortest burst time.
#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Process ID
    }

    // Sorting burst time in ascending order using selection sort
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i]; bt[i] = bt[pos]; bt[pos] = temp;
        temp = p[i]; p[i] = p[pos]; p[pos] = temp;
    }

    wt[0] = 0; // Waiting time for first process is 0
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }

    avg_wt = (float)total / n;
    total = 0;

    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\nP%d\t\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = (float)total / n;
    printf("\n\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
}



//2. Shortest Remaining Time First (SRTF) - Preemptive
//In SRTF, if a new process arrives with a burst time shorter than the remaining time of the current process, the CPU is preempted and given to the new process.
#include <stdio.h>

int main() {
    int a[10], b[10], x[10], i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter arrival time and burst time for each process\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        x[i] = b[i]; // Store burst time in a temporary array
    }

    b[9] = 9999; // Initialize a large value for comparison

    for (time = 0; count != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
                smallest = i;
        }
        b[smallest]--; // Reduce remaining time

        if (b[smallest] == 0) {
            count++;
            end = time + 1;
            avg = avg + end - a[smallest] - x[smallest];
            tt = tt + end - a[smallest];
        }
    }

    printf("\nAverage Waiting Time = %.2lf", avg / n);
    printf("\nAverage Turnaround Time = %.2lf\n", tt / n);
    return 0;
}
