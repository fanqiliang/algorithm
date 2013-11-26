#include <stdio.h>

void func(int n) {
    int store[n][n];
    int i;
    int j;
    int r = 0;
    int l = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            store[i][j] = 0;
        }
    }
    if (n == 1) {
        printf("1");
        return;
    }
    r = (n-1) / 2;
    store[l][r] = 1;
    for (i = 2; i <= n*n; i++) {
        if (l == 0 && r == n-1) {
            l = 1;
            r = n-1;
            store[l][r] = i;
            continue;
        }
        l = (l+n-1) % n;
        r = (r+1) % n;
        if (store[l][r] != 0) {
            l = (l+2) % n;
            r = (r+n-1) % n;
            store[l][r] = i;
        } else { 
            store[l][r] = i;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j != 0 && store[i][j-1] < 10) 
                printf("   %d", store[i][j]);
            else
                printf("  %d", store[i][j]);
            if (j == n-1) 
                printf("\n");
        }
    }
}

void func_1(int n) {
    int store[n][n];
    int i;
    int j;
    int t = 1;
    int temp;

    for (i = 0; i < n;i ++) {
        for (j = 0; j <n; j++) {
            store[i][j] = t;
            t++;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if((i != j) && (i+j != n-1)) {
                temp = store[i][j];
                store[i][j] = store[n-1-i][n-1-j];
                store[n-1-i][n-1-j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j != 0 && store[i][j-1] < 10) 
                printf("   %d", store[i][j]);
            else
                printf("  %d", store[i][j]);
            if (j == n-1) 
                printf("\n");
        }
    }
}


int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    if (n == 0) 
        return 0;
    else if (n % 4 == 0)
        func_1(n);
    else if (n % 2 == 1)
        func(n);
    else 
        return 0;
}
