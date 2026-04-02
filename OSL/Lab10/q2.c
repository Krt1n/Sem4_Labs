#include <stdio.h>
#include <stdlib.h>

int findLRU(int *time, int framesCount) {
    int min = time[0], pos = 0;

    for (int i = 1; i < framesCount; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, framesCount;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int *pages = (int *)malloc(n * sizeof(int));

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &framesCount);

    int *frames = (int *)malloc(framesCount * sizeof(int));
    int *time = (int *)malloc(framesCount * sizeof(int));

    int faults = 0, hits = 0, counter = 0;

    for (int i = 0; i < framesCount; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\n--- LRU Page Replacement ---\n");

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < framesCount; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                hits++;
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = -1;

            for (int j = 0; j < framesCount; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
                pos = findLRU(time, framesCount);

            counter++;
            frames[pos] = pages[i];
            time[pos] = counter;
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        for (int j = 0; j < framesCount; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    float hitRatio = (float)hits / n;

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Hits = %d\n", hits);
    printf("Hit Ratio = %.2f\n", hitRatio);

    free(pages);
    free(frames);
    free(time);

    return 0;
}