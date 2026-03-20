#include <stdio.h>

#define N 5
#define M 3

void checkRequest(int p, int req[], int available[], int allocation[N][M], int need[N][M]) {

    printf("\n\nChecking request for P%d: ", p);
    for(int i = 0; i < M; i++)
        printf("%d ", req[i]);

    for(int i = 0; i < M; i++) {
        if(req[i] > need[p][i]) {
            printf("\nError: Exceeds Need\n");
            return;
        }
    }

    for(int i = 0; i < M; i++) {
        if(req[i] > available[i]) {
            printf("\nResources not available. Must wait.\n");
            return;
        }
    }

    for(int i = 0; i < M; i++) {
        available[i] -= req[i];
        allocation[p][i] += req[i];
        need[p][i] -= req[i];
    }

    printf("\nRequest can be GRANTED (Safe state maintained)\n");
}

int main() {

    int allocation[N][M] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[N][M] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int available[M] = {3,3,2};
    int need[N][M];

    printf("\nNeed Matrix:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int finish[N] = {0};
    int safeSeq[N];
    int work[M];

    for(int i = 0; i < M; i++)
        work[i] = available[i];

    int count = 0;

    while(count < N) {
        int found = 0;

        for(int i = 0; i < N; i++) {
            if(finish[i] == 0) {
                int possible = 1;

                for(int j = 0; j < M; j++) {
                    if(need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    for(int j = 0; j < M; j++)
                        work[j] += allocation[i][j];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == N) {
        printf("\nSystem is in SAFE state\nSafe Sequence: ");
        for(int i = 0; i < N; i++)
            printf("P%d ", safeSeq[i]);
    } else {
        printf("\nSystem is NOT in safe state\n");
    }

    // 🔹 Requests
    int req1[M] = {1,0,2};
    checkRequest(1, req1, available, allocation, need);

    int req2[M] = {3,3,0};
    checkRequest(4, req2, available, allocation, need);

    int req3[M] = {0,2,0};
    checkRequest(0, req3, available, allocation, need);

    return 0;
}