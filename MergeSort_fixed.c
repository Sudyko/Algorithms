#include <stdlib.h>
#include <stdio.h>

void __fastcall merge(int* arr, int* left, int numL, int* right, int numR) {
    int i = 0, j = 0, k = 0;
    while (i < numL && j < numR) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while (i < numL)
        arr[k++] = left[i++];

    while (j < numR)
        arr[k++] = right[j++];
}

void __fastcall mergeSort(int* arr, int n) {
    if (n < 2) return;
    int mid = n / 2;

    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((n - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);

    free(left);
    free(right);
}

int main() {
    int arr[14] = { 10, 9, 8, 7, 6, 5, 4, 7, 5, 3, 1, 3, 2, 1 };
    int count = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, count);

    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}