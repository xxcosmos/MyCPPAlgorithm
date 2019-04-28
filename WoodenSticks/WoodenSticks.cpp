//
// Created by 张啸宇 on 2019-04-22.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int len, w;
} wood[5002];

bool operator<(const node &l, const node &r) {
    return (l.len < r.len) || (l.len == r.len && l.w < r.w);
}

int flag[5002];

int wooden_sticks() {
    int t, n, i, j, s, m;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(flag, 0, sizeof(flag));
        for (i = 0; i < n; i++)
            cin >> wood[i].len >> wood[i].w;
        sort(wood, wood + n);
        s = 0;
        for (i = 0; i < n; i++) {
            if (flag[i] == 0) {
                s++;
                m = wood[i].w;
                for (j = i + 1; j < n; j++) {
                    if (flag[j] == 1)continue;
                    if (m <= wood[j].w) {
                        flag[j] = 1;
                        m = wood[j].w;
                    }
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}