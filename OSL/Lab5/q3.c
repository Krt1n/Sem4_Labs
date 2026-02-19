//3. Write a C program to simulate Earliest-Deadline-First scheduling for real time systems.
#include <stdio.h>

struct Task {
    int id;
    int burst;
    int period;
    int remaining;
    int deadline;
};

int gcd(int a, int b) {
    while (b) { a %= b; int t = a; a = b; b = t; }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n, i, time, hyperperiod = 1;
    printf("Enter number of periodic processes: ");
    scanf("%d", &n);

    struct Task t[n];
    for (i = 0; i < n; i++) {
        t[i].id = i + 1;
        printf("Enter Burst and Period for P%d: ", t[i].id);
        scanf("%d %d", &t[i].burst, &t[i].period);
        t[i].remaining = 0;
        t[i].deadline = 0;
        hyperperiod = lcm(hyperperiod, t[i].period);
    }

    printf("\n--- EDF Execution Timeline (Hyperperiod: %d) ---\n", hyperperiod);
    
    int last_pid = -1;
    int start_time = 0;

    for (time = 0; time <= hyperperiod; time++) {
        // 1. Check for new arrivals/deadline resets
        for (i = 0; i < n; i++) {
            if (time % t[i].period == 0 && time < hyperperiod) {
                t[i].remaining = t[i].burst;
                t[i].deadline = time + t[i].period;
            }
        }

        // 2. Find task with Earliest Deadline
        int current_task = -1;
        int min_deadline = 9999;
        for (i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                if (t[i].deadline < min_deadline) {
                    min_deadline = t[i].deadline;
                    current_task = i;
                }
            }
        }

        // 3. Print only when the process CHANGES
        int current_pid = (current_task == -1) ? 0 : t[current_task].id; // 0 represents IDLE
        
        if (current_pid != last_pid) {
            if (time > 0) {
                printf("Time %d - %d: ", start_time, time);
                if (last_pid == 0) printf("IDLE\n");
                else printf("P%d\n", last_pid);
            }
            start_time = time;
            last_pid = current_pid;
        }

        // 4. Execute 1 unit of time
        if (current_task != -1) {
            t[current_task].remaining--;
        }
        
        if (time == hyperperiod) break; 
    }

    return 0;
}