#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//二分查找
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

void LIS(int Array[], int n) {
    int B[n];
    int BB[n];
    int BBB[n];
    int BBBB[n];
    int len = 1;
    B[0] = Array[0];//存储LIS最小的末尾
    BB[0] = 0;      //存储LIS最小末尾的位置
    BBB[0] = 0;     //存储每一个数在最小末尾序列中所出现过的位置
    for (int i = 0; i < n; i++) {
        BBBB[i] = -1;//存储一个最长子序列
    }
    for (int i = 1; i < n; i++) {
        if (Array[i] > B[len-1]) {
            B[len] = Array[i];
            BB[len] = i;
            BBB[i] = len;
            len++;
        } else {
            int m = BinarySearch(B, Array[i], len);
            if (B[m] != Array[i]) {
                B[m] = Array[i];
            }
            BBB[i] = m;
        }
    }
    int lin = len-1;
    for (int i = n-1; i >=0 && lin >= 0; i--) {
        if (BBBB[len-1] == -1 && BBB[i] == len-1) {
            BBBB[len-1] = Array[i];
            lin--;
        }
        if (BBBB[len-1] != -1 
                && BBBB[lin+1] != -1 
                && BBB[i] == lin 
                && BBBB[lin+1] > Array[i]) {
            BBBB[lin] = Array[i];
            lin--;
        }
    }
    printf("最长递增子序列的长度为：%d\n", len);
    printf("最长递增子序列为:\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", BBBB[i]);
    }
    printf("\n");
}

//最长递增子序列，时间复杂度为nlog（n）
int main() {
    int n;
    printf("please input n:");
    scanf("%d", &n);
    int Array[n];

    //随机生成n个数
    printf("生成的随机序列为：\n");
    srand((unsigned)time(NULL));
    for (int i = 0, t = 0; i < n; i++) {
        Array[i] = rand()%n;
        printf("%d ", Array[i]);
        t++;
        if (t == 10) {
            printf("\n");
            t = 0;
        }
    }
    printf("\n");

    LIS(Array, n);
}
