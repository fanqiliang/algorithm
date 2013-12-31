#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int BinarySearch(int B[], int value, int len) {
    int begin = 0;
    int end = len - 1;
    while (begin <= end) {
        int mid = begin + (end-begin) / 2;
        if (value == B[mid])
            return mid;
        else if (B[mid] > value)
            end = mid - 1;
        else 
            begin = mid + 1;
    }
    return begin;
}

void LIS(int Array[], int n, int in) {
    int B[n];
    int BB[n];
    int BBB[n];
    int BBBB[in+1];
    int len = 1;
    B[0] = Array[0];
    BB[0] = 0;
    BBB[0] = 0;
    for (int i = 0; i < in+1; i++) {
        BBBB[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        if (Array[i] > B[len-1]) {
            B[len] = Array[i];
            BB[len] = i;
            BBB[i] = len;
            len++;
        } else {
            int m = BinarySearch(B, Array[i], len);
            printf("m = %d\n", m);
            if (B[m] != Array[i]) {
                B[m] = Array[i];
            }
            BBB[i] = m;
        }
    }
    //for (int i = 0; i < len; i++) {
    //    printf("B[] = %d\n", B[i]);
    //}
    //for (int i = 0; i < n; i++) {
    //    printf("BBB[%d] = %d\n", i, BBB[i]);
    //}
    if (in+1 > len) {
        printf("in is too bigan.\n");
        exit(0);
    }
    int lin = in;
    for (int i = n-1; i >=0 && lin >= 0; i--) {
        if (BBBB[in] == -1 && BBB[i] == in) {
            BBBB[in] = Array[i];
            lin--;
        }
        if (BBBB[in] != -1 
                && BBBB[lin+1] != -1 
                && BBB[i] == lin 
                && BBBB[lin+1] > Array[i]) {
            BBBB[lin] = Array[i];
            lin--;
        }
    }
    printf("最长递增子序列为:");
    for (int i = 0; i <= in; i++) {
        printf("%d ", BBBB[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("please input n:");
    scanf("%d", &n);
    int Array[n];
   srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        Array[i] = rand()%n;
        //printf("Array[%d] = %d\n", i, Array[i]);
    }
    int in;
    printf("please input tht in:");
    scanf("%d", &in);
    LIS(Array, n ,in-1);
}
