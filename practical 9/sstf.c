#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = 8;
    int head = 53;
    int visited[8] = {0};
    int total = 0;

    printf("Disk Request Sequence: ");
    for(int i = 0; i < n; i++)
        printf("%d ", req[i]);

    printf("\nInitial Head Position: %d\n", head);

    for(int i = 0; i < n; i++) {
        int min = 9999, index = -1;

        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(head - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        total += min;
        head = req[index];
        visited[index] = 1;
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
