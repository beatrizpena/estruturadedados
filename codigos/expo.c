#include <stdio.h>

int binary_search_range(int arr[], int start, int end, int target) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int exponential_search(int arr[], int size, int target) {
    if (arr[0] == target) {
        return 0;
    }
    int bound = 1;
    while (bound < size && arr[bound] < target) {
        bound *= 2;
    }
    return binary_search_range(arr, bound / 2, (bound < size ? bound : size - 1), target);
}
