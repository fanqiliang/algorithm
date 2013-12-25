#include <stdio.h>
#include <curses.h>
int main(void) 
{ 
    int i,j,n,k,a[100][100]={0}; 
    printf("n="); 
    scanf("%d",&n); 
    for(i=0,j=n/2,k=1;k<=n*n;k++) { 
        a[i][j]=k; 
        if(a[i+(i!=0?-1:n-1)][j+(j!=n-1?1:-j)]) /* 判断下个存放的位置是否被占 */ 
            i++; 
        else                         /* 如下个位置没被占，指向下个位置 */ 
            i=i!=0?i-1:n-1,j=j!=n-1?j+1:0; 
    } 
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) 
        printf("%5d",a[i][j]); 
        printf("\n\n"); 
    } 
    return 0; 
}
