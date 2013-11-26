#include<stdio.h>

int func_a(int n, int k) {
    if (n <= 0 || k <= 0) { 
        return 0;
    }
    else if (n == 1 || k == 1)
        return 1;
    else if (n < k)
        return func_a(n, n);
    else if (n == k)
        return (1 + func_a(n, k-1));
    else 
        return (func_a(n-k, k) + func_a(n, k-1));
}

int func_b(int n, int k) {
    int i;

    if (n < k || k <= 0 || n <= 0)
        return 0;
    else if (k == 1)
        return 1;
    else 
        return (func_b(n-k, k) + func_b(n-1, k-1));
}

int func_c(int n, int k) {
    if(n <=0 || k <=0) 
        return 0;
    else if(n == 1 || k == 1) 
        return 1;
    else if(n < k) 
        return func_c(n, n);
    else if(n == k && (n%2 == 1)) 
        return func_c(n, n-1) + 1;
    else if(n == k && (n%2 == 0)) 
        return func_c(n, n-1);
    else 
        return func_c(n, k-2)+func_c(n-k, k);
}

int func_d(int n) {
    int i;
    int count = 0;
    for (i = 1; i < n-1; i++) {
        count++;
    }
    return count;
}

int main() {
    int n;
    int k;
    printf("please input the number of n and k:\n");
    scanf("%d %d", &n, &k);
    printf("%d\n", func_a(n, n));
    printf("%d\n", func_b(n, k));
    printf("%d\n", func_a(n ,k));
    printf("%d\n", func_c(n ,n));
    printf("%d\n", func_d(n));
    printf("\n");
}
