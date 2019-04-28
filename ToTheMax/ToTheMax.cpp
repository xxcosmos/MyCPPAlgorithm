//
// Created by 张啸宇 on 2019-04-28.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp(const int a[], int n) {
    int i, f[101];//f[i]表示以i结尾子段最大和
    int max = -200000000;
    for (i = 2, f[1] = a[1]; i <= n; i++) {
        if (f[i - 1] > 0)
            //当前边那个f的值是正的时候
            f[i] = f[i - 1] + a[i];
        else
            //负的时候,以a[i]结尾的就不是最大的了
            f[i] = a[i];

        if (f[i] > max)
            max = f[i];
    }
    return max;
}

int main() {
    int n, i, he, j;
    int a[105][105], k;
    int sum[105], maxn;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    maxn = -200000000;
    for (i = 1; i <= n; i++) {
        memset(sum, 0, sizeof(sum));
        for (j = i; j <= n; j++) {
            for (k = 1; k <= n; k++)
                sum[k] += a[j][k];
            he = dp(sum, n);
            if (he > maxn) maxn = he;
        }
    }

    printf("%d\n", maxn);
    return 0;
}