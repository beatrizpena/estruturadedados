#include <stdio.h>

int interpolation_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]));
        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}
