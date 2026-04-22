//Priority scheduling can be tricky because "higher priority" can mean a higher number (e.g., 10) or a lower number (e.g., 0). In these codes, we assume lower numerical value = higher priority (similar to how 1st place is better than 2nd).

//1. Priority Scheduling (Non-Preemptive)
//Logic: The process with the highest priority is selected and runs to completion. No process can interrupt it once it starts.
#include <stdio.h>

struct Process {
    int pid, bt, pri, wt, tat;
};

void main() {
    int n, i, j;
    struct Process p[20], temp;
    float avg_wt, avg_tat, total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].pri);
    }

    // Sort processes based on priority (Selection Sort)
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].pri > p[j].pri) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wt = 0;
    for(i = 1; i < n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        total_wt += p[i].wt;
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt, p[i].pri, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat/n);
}



//2. Priority Scheduling (Preemptive)
//Logic: If a new process arrives with a higher priority than the one currently running, the CPU is preempted (the current process is paused) and given to the new process.
#include <stdio.h>

struct Process {
    int at, bt, pri, wt, tat, rt;
};

int main() {
    int n, i, time = 0, count = 0, shortest;
    struct Process p[10];
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT, BT, and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pri);
        p[i].rt = p[i].bt; // Remaining Time
    }

    p[9].pri = 9999; // Sentinel value (lowest priority)

    while(count != n) {
        shortest = 9;
        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].pri < p[shortest].pri && p[i].rt > 0)
                shortest = i;
        }

        p[shortest].rt--;

        if(p[shortest].rt == 0) {
            count++;
            int end_time = time + 1;
            p[shortest].tat = end_time - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            total_wt += p[shortest].wt;
            total_tat += p[shortest].tat;
        }
        time++;
    }

    printf("\nAvg WT: %.2f", total_wt/n);
    printf("\nAvg TAT: %.2f\n", total_tat/n);
    return 0;
}
