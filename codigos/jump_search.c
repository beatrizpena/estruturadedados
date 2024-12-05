#include <stdio.h>
#include <math.h>

int jump_search(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;
    while (arr[(step < size ? step : size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }
    for (int i = prev; i < step && i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
