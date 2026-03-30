#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int visited[8] = {0};
    int head = 53, total = 0;

    for(int i = 0; i < 8; i++) {
        int min = 9999, index = -1;

        for(int j = 0; j < 8; j++) {
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

    printf("Total Head Movement = %d\n", total);

    return 0;
}