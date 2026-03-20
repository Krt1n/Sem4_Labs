#include <stdio.h>

#define N 5
#define M 3

int main() {

    int allocation[N][M] = {
        {0,1,0},
        {2,0,0},
        {3,0,3},
        {2,1,1},
        {0,0,2}
    };

    int request[N][M] = {
        {0,0,0},
        {2,0,2},
        {0,0,0},
        {1,0,0},
        {0,0,2}
    };

    int available[M] = {0,0,0};

    int work[M];
    int finish[N];

    for(int i = 0; i < M; i++)
        work[i] = available[i];

    for(int i = 0; i < N; i++) {
        int allZero = 1;
        for(int j = 0; j < M; j++) {
            if(allocation[i][j] != 0) {
                allZero = 0;
                break;
            }
        }
        finish[i] = allZero ? 1 : 0;
    }
    while(1) {
        int found = 0;

        for(int i = 0; i < N; i++) {
            if(finish[i] == 0) {

                int possible = 1;

                for(int j = 0; j < M; j++) {
                    if(request[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    for(int j = 0; j < M; j++)
                        work[j] += allocation[i][j];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    int deadlock = 0;
    printf("\nDeadlocked Processes: ");
    for(int i = 0; i < N; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("None (System is SAFE)\n");
    else
        printf("\nSystem is in DEADLOCK state\n");

    printf("\n\nAfter P2 requests 1 more instance of C:\n");
    request[2][2] += 1;

    for(int i = 0; i < M; i++)
        work[i] = available[i];

    for(int i = 0; i < N; i++) {
        int allZero = 1;
        for(int j = 0; j < M; j++) {
            if(allocation[i][j] != 0) {
                allZero = 0;
                break;
            }
        }
        finish[i] = allZero ? 1 : 0;
    }

    while(1) {
        int found = 0;

        for(int i = 0; i < N; i++) {
            if(finish[i] == 0) {

                int possible = 1;

                for(int j = 0; j < M; j++) {
                    if(request[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    for(int j = 0; j < M; j++)
                        work[j] += allocation[i][j];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    deadlock = 0;
    printf("Deadlocked Processes: ");
    for(int i = 0; i < N; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("None (System is SAFE)\n");
    else
        printf("\nSystem is still in DEADLOCK state\n");

    return 0;
}