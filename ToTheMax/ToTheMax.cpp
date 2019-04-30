//
// Created by 张啸宇 on 2019-04-28.
//
#include<cstdio>
#include<cstdlib>
#include<cstring>

int maxn = 0x7fffffff;

int dp(const int a[], int n) {
    int i, f[101];//f[i]表示以i结尾子段最大和
    int max = maxn;
    for (i = 2, f[1] = a[1]; i <= n; i++) {
        if (f[i - 1] > 0)
            //当前边的f的值是正的时候
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


    int n, he;
    int a[105][105];
    int sum[105];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    int max = maxn;
    for (int i = 1; i <= n; i++) {
        memset(sum, 0, sizeof(sum));
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= n; k++)
                sum[k] += a[j][k];
            he = dp(sum, n);
            if (he > max) max = he;
        }
    }

    printf("%d\n", max);
    return 0;
}