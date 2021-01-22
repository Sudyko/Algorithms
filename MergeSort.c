#include <stdlib.h>
#include <stdio.h>

void Merge(int arr[], int start, int mid, int end) {
    int* res_arr = NULL;
    res_arr = (int*)malloc((end-start) * sizeof(int));

    int p = start;
    int q = mid + 1;
    int i = 0;
    
    while (p <= mid && q<= end) {
        if (arr[p] < arr[q])
            res_arr[i++] = arr[p++];
        else if (arr[p] >= arr[q])
            res_arr[i++] = arr[q++];
    }

    if (p <= mid) {
        while (p <= mid) {
            res_arr[i++] = arr[p++];
        }
    }
    else if (q <= end) {
        while (q <= end) {
            res_arr[i++] = arr[q++];
        }
    }

    for (int j = start; j <= end; ++j) {
        arr[j] = res_arr[j - start];
    }
    //free(res_arr);
	/* Troubles with freeing memory */
}

void MergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(arr, p, q);
        MergeSort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
}

int main()
{
    int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int count = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, count-1);

    for (int i = 0; i < count; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}