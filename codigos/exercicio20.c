#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funções de Ordenação
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void selection_sort(int arr[], int size);

// Funções de Busca
int binary_search(int arr[], int size, int target);
int interpolation_search(int arr[], int size, int target);

// Funções Auxiliares
void print_array(int arr[], int size);
void get_array(int arr[], int size);

int main() {
    int choice, sort_choice, search_choice;
    int size, target, result;
    
    printf("Digite o tamanho da lista: ");
    scanf("%d", &size);

    int arr[size];
    printf("Digite os elementos da lista:\n");
    get_array(arr, size);

    printf("Escolha a operação:\n");
    printf("1. Ordenar Lista\n");
    printf("2. Procurar Elemento\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Escolha o algoritmo de ordenação:\n");
        printf("1. Quick Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Selection Sort\n");
        scanf("%d", &sort_choice);

        if (sort_choice == 1) {
            quick_sort(arr, 0, size - 1);
            printf("Lista ordenada (Quick Sort):\n");
        } else if (sort_choice == 2) {
            merge_sort(arr, 0, size - 1);
            printf("Lista ordenada (Merge Sort):\n");
        } else if (sort_choice == 3) {
            selection_sort(arr, size);
            printf("Lista ordenada (Selection Sort):\n");
        } else {
            printf("Opção inválida.\n");
            return 1;
        }
        print_array(arr, size);
    } else if (choice == 2) {
        printf("Escolha o algoritmo de busca:\n");
        printf("1. Binary Search\n");
        printf("2. Interpolation Search\n");
        scanf("%d", &search_choice);

        printf("Digite o elemento a ser buscado: ");
        scanf("%d", &target);

        if (search_choice == 1) {
            result = binary_search(arr, size, target);
            printf("Resultado da busca (Binary Search): %s\n", result != -1 ? "Encontrado" : "Não encontrado");
        } else if (search_choice == 2) {
            result = interpolation_search(arr, size, target);
            printf("Resultado da busca (Interpolation Search): %s\n", result != -1 ? "Encontrado" : "Não encontrado");
        } else {
            printf("Opção inválida.\n");
            return 1;
        }
    } else {
        printf("Escolha inválida.\n");
        return 1;
    }

    return 0;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

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

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void get_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}
