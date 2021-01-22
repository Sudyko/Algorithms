#include <stdio.h>

void __fastcall swap(int a[], int& i, int& j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void __fastcall InsertionSort(int a[], int& count) {
    for (int i = 1; i < count; i++) {
        int key = a[i];
        int j = i - 1;
        while (j > -1 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int count = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, count);

    for (int i = 0; i < count; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}