//
// Created by 张啸宇 on 2019-04-21.
//


#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = 30;

int t[maxn], f[maxn], d[maxn];

struct node {
    int id;
    int f;
    int d;

    friend bool operator<(node a, node b) {
        return (a.f == b.f) ? a.id > b.id : a.f < b.f;
    }
};

node fish[maxn];

int times[maxn][maxn];     //记录每个湖钓鱼时间

int gone_fishing() {
    int n, h;
    while (scanf("%d", &n) != EOF && n) {
        scanf("%d", &h);
        memset(times, 0, sizeof(times));
        h = h * 12;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &fish[i].f);
            fish[i].id = i;
        }
        for (int i = 1; i <= n; i++) scanf("%d", &fish[i].d);
        for (int i = 1; i <= n - 1; i++) scanf("%d", &t[i]);

        int maxans = 0;
        int maxk = 1;
        for (int i = 1; i <= n; i++) {
            int tc = 0;
            for (int j = 1; j < i; j++) tc += t[j];
            priority_queue<node> p;
            for (int j = 1; j <= i; j++) p.push(fish[j]); //将湖1~X的鱼量放入从大到小排的优先队列
            int ans = 0;
            int t = h - tc;
            for (int j = 1; j <= t; j++) {
                node foo = p.top();
                ans += foo.f;
                times[i][foo.id] += 5;
                p.pop();
                p.push(node{foo.id, max(foo.f - foo.d, 0), foo.d});
            }
            if (maxans < ans) {
                maxans = ans;
                maxk = i;
            }
        }
        for (int i = 1; i < n; i++) printf("%d, ", times[maxk][i]);
        printf("%d\n", times[maxk][n]);
        printf("Number of fish expected: %d\n\n", maxans);
    }
    return 0;
}