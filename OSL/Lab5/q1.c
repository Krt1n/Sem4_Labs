/*
Write a menu-driven C/C++ program to simulate the following CPU scheduling algorithms:
1) FCFS
2) SRTF
3) Round Robin (Time Quantum = 10)
4) Non-preemptive Priority (Higher number = Higher priority)
*/
#include <stdio.h>
#include <limits.h>

#define N 4

typedef struct {
    int pid;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
} Process;

void reset(Process p[]) {
    for(int i=0;i<N;i++) {
        p[i].remaining = p[i].burst;
        p[i].completion = 0;
    }
}

void calculate(Process p[]) {
    for(int i=0;i<N;i++) {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }
}

void print(Process p[]) {
    float avg_wt=0, avg_tat=0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<N;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].arrival,p[i].burst,
        p[i].completion,p[i].turnaround,p[i].waiting);

        avg_wt += p[i].waiting;
        avg_tat += p[i].turnaround;
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/N);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/N);
}

void fcfs(Process p[]) {
    int time=0;

    for(int i=0;i<N;i++) {
        if(time < p[i].arrival)
            time = p[i].arrival;

        time += p[i].burst;
        p[i].completion = time;
    }

    calculate(p);
    print(p);
}

void srtf(Process p[]) {
    int complete=0, time=0, minm, shortest=0;
    int finish_time;
    int check=0;

    while(complete != N) {
        minm = INT_MAX;
        check = 0;

        for(int j=0;j<N;j++) {
            if(p[j].arrival <= time &&
               p[j].remaining > 0 &&
               p[j].remaining < minm) {
                minm = p[j].remaining;
                shortest = j;
                check = 1;
            }
        }

        if(check==0) {
            time++;
            continue;
        }

        p[shortest].remaining--;

        if(p[shortest].remaining==0) {
            complete++;
            finish_time = time+1;
            p[shortest].completion = finish_time;
        }

        time++;
    }

    calculate(p);
    print(p);
}

void roundRobin(Process p[], int quantum) {
    int time=0, done;

    do {
        done = 1;
        for(int i=0;i<N;i++) {
            if(p[i].arrival <= time && p[i].remaining > 0) {
                done = 0;

                if(p[i].remaining > quantum) {
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    time += p[i].remaining;
                    p[i].completion = time;
                    p[i].remaining = 0;
                }
            }
        }
    } while(!done);

    calculate(p);
    print(p);
}

void priority(Process p[]) {
    int time=0, completed=0;

    while(completed < N) {
        int highest=-1;
        int maxPriority=-1;

        for(int i=0;i<N;i++) {
            if(p[i].arrival <= time &&
               p[i].completion==0) {

                if(p[i].priority > maxPriority) {
                    maxPriority = p[i].priority;
                    highest = i;
                }
            }
        }

        if(highest != -1) {
            time += p[highest].burst;
            p[highest].completion = time;
            completed++;
        } else {
            time++;
        }
    }

    calculate(p);
    print(p);
}

int main() {

    Process p[N] = {
        {1,0,60,3,0,0,0,0},
        {2,3,30,2,0,0,0,0},
        {3,4,40,1,0,0,0,0},
        {4,9,10,4,0,0,0,0}
    };

    int choice;

    printf("1. FCFS\n");
    printf("2. SRTF\n");
    printf("3. Round Robin (Quantum=10)\n");
    printf("4. Non-Preemptive Priority\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    reset(p);

    switch(choice) {
        case 1: fcfs(p); break;
        case 2: srtf(p); break;
        case 3: roundRobin(p,10); break;
        case 4: priority(p); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
