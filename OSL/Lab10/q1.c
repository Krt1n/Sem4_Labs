#include <stdio.h>
#include <stdlib.h>

int isPresent(int *frames, int framesCount, int page) {
    for (int i = 0; i < framesCount; i++) {
        if (frames[i] == page)
            return 1;
    }
    return 0;
}

void FIFO(int *pages, int n, int framesCount) {
    int *frames = (int *)malloc(framesCount * sizeof(int));
    int i, j, index = 0, faults = 0;

    for (i = 0; i < framesCount; i++)
        frames[i] = -1;

    printf("\n--- FIFO Page Replacement ---\n");

    for (i = 0; i < n; i++) {
        if (!isPresent(frames, framesCount, pages[i])) {
            frames[index] = pages[i];
            index = (index + 1) % framesCount;
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        for (j = 0; j < framesCount; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults (FIFO) = %d\n", faults);
    free(frames);
}

int findOptimal(int *pages, int n, int *frames, int framesCount, int current) {
    int farthest = current, index = -1;

    for (int i = 0; i < framesCount; i++) {
        int j;
        for (j = current + 1; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }

    return (index == -1) ? 0 : index;
}

void Optimal(int *pages, int n, int framesCount) {
    int *frames = (int *)malloc(framesCount * sizeof(int));
    int faults = 0;

    for (int i = 0; i < framesCount; i++)
        frames[i] = -1;

    printf("\n--- Optimal Page Replacement ---\n");

    for (int i = 0; i < n; i++) {
        if (!isPresent(frames, framesCount, pages[i])) {
            int pos = -1;


            for (int j = 0; j < framesCount; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
                pos = findOptimal(pages, n, frames, framesCount, i);

            frames[pos] = pages[i];
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

    printf("Total Page Faults (Optimal) = %d\n", faults);
    free(frames);
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

    FIFO(pages, n, framesCount);
    Optimal(pages, n, framesCount);

    free(pages);
    return 0;
}