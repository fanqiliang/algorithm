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

    for (int i = low+1; i <= high; i++) {
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
    int j = 0, i = 0;
    int min;
    int temp;
    for (int gap = (high+1)/2; gap > 0; gap /= 2) {
        for (i = low; i <= high; i += gap) {
            min = i;
            for (j = i; j <= high; j += gap) {
                if (Array[j] < Array[min])
                    min = j;
            }
            if (i != min) {
                temp = Array[i];
                Array[i] = Array[min];
                Array[min] = temp;
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
        srand((unsigned)clock());
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
        clock_t start1, end1;
        start = clock();
        printf("QuickSort:  ");
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            start1 = clock();
            QuickSort(Array, low, high);
            end1 = clock();
            printf("%f  ", (double)(end1-start1));
        }
        end = clock();
        if (n == 10) {
            for (int i = 0; i < 10; i++) {
                printf("%d ", Array[i]);
            }
            printf("\n");
        }
        printf("Average: %f\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        printf("BullbeSort:  ");
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            start1 = clock();
            BullbeSort(Array, low, high);
            end1 = clock();
            printf("%f  ", (double)(end1-start1));
        }
        end = clock();
        if (n == 10) {
            for (int i = 0; i < 10; i++) {
                printf("%d ", Array[i]);
            }
            printf("\n");
        }
        printf("Average: %f\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        printf("ShellSort:  ");
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            start1 = clock();
            ShellSort(Array, low, high);
            end1 = clock();
            printf("%f  ", (double)(end1-start1));
        }
        end = clock();
        if (n == 10) {
            for (int i = 0; i < 10; i++) {
                printf("%d ", Array[i]);
            }
            printf("\n");
        }
        printf("Average: %f\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        printf("MergeSort:  ");
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            start1 = clock();
            MergeSort(Array, low, high);
            end1 = clock();
            printf("%f  ", (double)(end1-start1));
        }
        end = clock();
        if (n == 10) {
            for (int i = 0; i < 10; i++) {
                printf("%d ", Array[i]);
            }
            printf("\n");
        }
        printf("Average: %f\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        printf("InsertSort:  ");
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            start1 = clock();
            InsertSort(Array, low, high);
            end1 = clock();
            printf("%f  ", (double)(end1-start1));
        }
        end = clock();
        if (n == 10) {
            for (int i = 0; i < 10; i++) {
                printf("%d ", Array[i]);
            }
            printf("\n");
        }
        printf("Average: %f\n", (double)((end-start)/5));
        srand((unsigned)time(NULL));
        start = clock();
        printf("BucketSort:  ");
        for (int j = 0; j < 5; j++) {
            memcpy(Array, array, n*sizeof(int));
            start1 = clock();
            BucketSort(Array, low, high);
            end1 = clock();
            printf("%f  ", (double)(end1-start1));
        }
        end = clock();
        if (n == 10) {
            for (int i = 0; i < 10; i++) {
                printf("%d ", Array[i]);
            }
            printf("\n");
        }
        printf("Average: %f\n", (double)((end-start)/5));
    }
}
