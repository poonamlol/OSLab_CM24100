#include <stdio.h>

int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12, frames = 3;

    int frame[10], i, j, k, pos;
    int hits = 0, faults = 0;

    // Initialize frames
    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("Page Reference String: ");
    for(i = 0; i < n; i++)
        printf("%d ", pages[i]);

    printf("\nNumber of Frames: %d\n\n", frames);

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already in frame (hit)
        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                hits++;
                found = 1;
                break;
            }
        }

        // If not found, it's a fault
        if(!found) {
            int farthest = -1;
            pos = -1;

            for(j = 0; j < frames; j++) {
                int k;
                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k])
                        break;
                }

                // If page not used again
                if(k == n) {
                    pos = j;
                    break;
                }

                // Find farthest used page
                if(k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            faults++;
        }
    }

    printf("Page Hits = %d\n", hits);
    printf("Page Faults = %d\n", faults);
    printf("Hit Ratio = %.2f%%\n", (hits / (float)n) * 100);
    printf("Fault Ratio = %.2f%%\n", (faults / (float)n) * 100);

    return 0;
}