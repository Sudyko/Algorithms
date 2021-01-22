#include <stdlib.h>
#include <stdio.h>

void __fastcall swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int Left(int i) {
    return 2 * i;
}

int Right(int i) {
    return 2 * i + 1;
}

void __fastcall MaxHeapify(int arr[], int size, int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if (l < size && arr[l] > arr[i])
        largest = l;
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr, i, largest);
        MaxHeapify(arr, size, largest);
    }
}

void __fastcall HeapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        MaxHeapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; --i) {
        swap(arr, 0, i);
        MaxHeapify(arr, i, 0);
    }
}

int main() {
    int arr[10] = { 10, 9, 123, 7, 6, 321, 4, 334, 2, 1 };
    int count = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, count);

    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}