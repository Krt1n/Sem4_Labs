#include <stdio.h>

void printSummary(int allocation[], int process[], int np, int holes[], int nh) {
    int count = 0;
    int remainingMem = 0;
    
    printf("\nAllocation Results:\n");
    for(int i = 0; i < np; i++) {
        printf("Process %d (%dK) -> ", i+1, process[i]);
        if(allocation[i] != -1) {
            printf("Hole %d\n", allocation[i]+1);
            count++;
        } else {
            printf("Not Allocated (WAITING)\n");
        }
    }

    for(int i = 0; i < nh; i++) remainingMem += holes[i];

    printf("------------------------------\n");
    printf("Efficiency: %d/%d processes allocated.\n", count, np);
    printf("Total External Fragmentation: %dK\n", remainingMem);
    printf("------------------------------\n");
}

void firstFit(int holes[], int nh, int process[], int np) {
    int allocation[np];
    for(int i = 0; i < np; i++) allocation[i] = -1;

    for(int i = 0; i < np; i++) {
        for(int j = 0; j < nh; j++) {
            if(holes[j] >= process[i]) {
                allocation[i] = j;
                holes[j] -= process[i];
                break;
            }
        }
    }
    printf("\n--- FIRST FIT STRATEGY ---");
    printSummary(allocation, process, np, holes, nh);
}

void bestFit(int holes[], int nh, int process[], int np) {
    int allocation[np];
    for(int i = 0; i < np; i++) allocation[i] = -1;

    for(int i = 0; i < np; i++) {
        int bestIdx = -1;
        for(int j = 0; j < nh; j++) {
            if(holes[j] >= process[i]) {
                if(bestIdx == -1 || holes[j] < holes[bestIdx])
                    bestIdx = j;
            }
        }
        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            holes[bestIdx] -= process[i];
        }
    }
    printf("\n--- BEST FIT STRATEGY ---");
    printSummary(allocation, process, np, holes, nh);
}

void worstFit(int holes[], int nh, int process[], int np) {
    int allocation[np];
    for(int i = 0; i < np; i++) allocation[i] = -1;

    for(int i = 0; i < np; i++) {
        int worstIdx = -1;
        for(int j = 0; j < nh; j++) {
            if(holes[j] >= process[i]) {
                if(worstIdx == -1 || holes[j] > holes[worstIdx])
                    worstIdx = j;
            }
        }
        if(worstIdx != -1) {
            allocation[i] = worstIdx;
            holes[worstIdx] -= process[i];
        }
    }
    printf("\n--- WORST FIT STRATEGY ---");
    printSummary(allocation, process, np, holes, nh);
}

int main() {
    int holes_init[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int nh = 5, np = 4;

    int h1[5], h2[5], h3[5];
    for(int i=0; i<nh; i++) h1[i] = h2[i] = h3[i] = holes_init[i];

    firstFit(h1, nh, process, np);
    bestFit(h2, nh, process, np);
    worstFit(h3, nh, process, np);

    return 0;
}