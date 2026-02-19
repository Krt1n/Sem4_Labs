// Write a C program to simulate multi-level feedback queue scheduling algorithm.

#include <stdio.h>

struct Process {
    int id, burst, remaining, wait, turnaround;
};

int main() {
    int n, i, time = 0;
    struct Process p[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter burst time for P%d: ", p[i].id);
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;
    }

    printf("\n--- Gantt Chart ---\n0");

    for(i = 0; i < n; i++) {
        int execute = (p[i].remaining > 8) ? 8 : p[i].remaining;
        time += execute;
        p[i].remaining -= execute;
        printf(" -> [P%d] -> %d", p[i].id, time);
    }

    for(i = 0; i < n; i++) {
        if(p[i].remaining > 0) {
            int execute = (p[i].remaining > 16) ? 16 : p[i].remaining;
            time += execute;
            p[i].remaining -= execute;
            printf(" -> [P%d] -> %d", p[i].id, time);
        }
    }

    for(i = 0; i < n; i++) {
        if(p[i].remaining > 0) {
            time += p[i].remaining;
            p[i].remaining = 0;
            p[i].turnaround = time; 
            printf(" -> [P%d] -> %d", p[i].id, time);
        } else if (p[i].turnaround == 0) {
            p[i].turnaround = time; 
        }
    }

    printf("\n\nPID\tBurst\tWaiting\tTurnaround\n");
    float avgW = 0, avgT = 0;
    for(i = 0; i < n; i++) {
        p[i].wait = p[i].turnaround - p[i].burst;
        avgW += p[i].wait;
        avgT += p[i].turnaround;
        printf("P%d\t%d\t%d\t%d\n", p[i].id, p[i].burst, p[i].wait, p[i].turnaround);
    }
    printf("\nAvg Waiting Time: %.2f", avgW/n);
    printf("\nAvg Turnaround Time: %.2f\n", avgT/n);

    return 0;
}