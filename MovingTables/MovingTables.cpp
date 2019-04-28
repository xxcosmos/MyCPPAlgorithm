//
// Created by 张啸宇 on 2019-04-22.
//
#include <cstdio>
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int moving_tables() {
    int n, m, a, b, max;
    cin >> n;
    while (n--) {
        cin >> m;
        int room[201] = {0};
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            a = (a + 1) / 2;
            b = (b + 1) / 2;
            if (a > b) {
                swap(a, b);
            }
            for (int j = a; j < b; ++j) {
                room[j]++;
            }
        }
        max = room[1];
        for (int i = 2; i < 201; ++i) {
            if (room[i] > max)
                max = room[i];
        }
        cout << max * 10 << endl;
    }
    return 0;
}