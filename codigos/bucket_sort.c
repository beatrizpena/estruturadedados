#include <stdio.h>
#include <stdlib.h>

void bucket_sort(float arr[], int size) {
    int buckets[size][size];
    int count[size];
    for (int i = 0; i < size; i++) count[i] = 0;
    for (int i = 0; i < size; i++) {
        int idx = (int)(arr[i] * size);
        buckets[idx][count[idx]++] = arr[i];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < count[i] - 1; j++) {
            for (int k = 0; k < count[i] - j - 1; k++) {
                if (buckets[i][k] > buckets[i][k + 1]) {
                    float temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
