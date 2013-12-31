#include "AllSorts.h"
#include <time.h>
#include <stdlib.h>

//冒泡排序
void BullbeSort(int Array[], int low ,int high) {
    for (int i = low; i <= high; i++) {
        for (int j = high; j > i; j--) {
            if (Array[j-1] > Array[j]) {
                int temp = Array[j-1];
                Array[j-1] = Array[j];
                Array[j] = temp;
            }
        }
    }
    return;
}

//插入排序
void InsertSort(int Array[], int low, int high) {

    for (int i = low+1; i < high; i++) {
        int temp = Array[i];
        int j = i - 1;
        while ((j >= low) && (Array[j] > temp)) {
            Array[j+1] = Array[j];
            j--;
        }
        Array[j+1] = temp;
    }
    return;
}

int Partition(int Array[], int low, int high) {
    int key = Array[low];

    while (low < high) {
        while (low < high && Array[high] >= key)
            high--;
        Array[low] = Array[high];
        while (low < high && Array[low] <= key)
            low++;
        Array[high] = Array[low];
    }
    Array[low] = key;
    return low;
}

//快速排序
void QuickSort(int Array[],  int low, int high) {
    int key = 0;

    if (low < high) {
        key = Partition(Array, low, high);
        QuickSort(Array, low, key-1);
        QuickSort(Array, key+1, high);
    }
    return;
}

//希尔排序
void ShellSort(int Array[], int low, int high) {
    int j = 0;
    for (int gap = high/2; gap > 0; gap /= 2) {
        for (int i = low; i < high; i++) {
            int temp = Array[i];
            for (j = i; j >= low && j+gap < high 
                    && temp > Array[j+gap]; j += gap) {
                temp = Array[j];
                Array[j] = Array[j+gap];
                Array[j+gap] = temp;
            }
        }
    }
    return;
}

//归并排序
void Merge(int Array[], int low, int mid, int high) {
    int lt = mid - low + 1;
    int left[lt];
    int rt = high - mid;
    int right[rt];
    int i,j,k;

    for (i = 0; i < lt; i++)
        left[i] = Array[low+i]; 
    for (i = 0; i < rt; i++)
        right[i] = Array[mid+1+i];

    for (i = 0, j = 0, k = low; i < lt && j < rt; k++) {
        if (left[i] < right[j]) {
            Array[k] = left[i];
            i++;
        }
        else {
            Array[k] = right[j];
            j++;
        }
    }
    if (lt < rt)
        for (; j < rt; j++, k++)
            Array[k] = right[j];
    else
        for (; i < lt; i++, k++)
            Array[k] = left[i];
    return;
}

void MergeSort(int Array[], int low, int high) {
    if (low < high) {
        int mid = (low+high) / 2;
        MergeSort(Array, low, mid);
        MergeSort(Array, mid+1, high);
        Merge(Array, low, mid, high);
    }
    return;
}

//桶排序
void BucketSort(int Array[], int low, int high) {
    int key = Array[low];
    for (int i = low+1; i <= high; i++) {
        if (key < Array[i])
            key = Array[i];
    }
    int buckets[key+1];
    for (int i = 0; i <= key; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < high-low+1; i++)
        (buckets[Array[i]])++;
    for (int i = 0, j = 0; j <= key; j++)
        for (int k = buckets[j]; k > 0; k--) {
            Array[i] = j;
            i++;
        }
    return;
}

int main() {
    int n = 0;
    for (int i = 0, n = 10; i < 5; i++, n = n*10) {
        if (n == 100000)
            n = 30000;
        int Array[n];
        int array[n];
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++) {
            Array[i] = rand()%n;
        }
        memcpy(array, Array, n*sizeof(int));
        printf("\n");
        int low = 0;
        int high = 0;
        high= sizeof(Array)/sizeof(int);
        printf("high = %d\n", high);
        high -= 1;
        clock_t start, end;
        start = clock();
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            QuickSort(Array, low, high);
        }
        end = clock();
        printf("QuickSort time is %f seconds\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            BullbeSort(Array, low, high);
        }
        end = clock();
        printf("BullbeSort time is %f seconds\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            ShellSort(Array, low, high);
        }
        end = clock();
        printf("ShellSort time is %f seconds\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            MergeSort(Array, low, high);
        }
        end = clock();
        printf("MerfeSort time is %f seconds\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            InsertSort(Array, low, high);
        }
        end = clock();
        printf("InsertSort time is %f seconds\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            BucketSort(Array, low, high);
        }
        end = clock();
        printf("BucketSort time is %f seconds\n", (double)((end-start)/5));
    }
   // for (int i = 0; i < 100000; i++) {
   //     printf("%d ", Array[i]);
   // }
   // printf("\n");
}
