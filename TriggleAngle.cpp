//
// Created by 张啸宇 on 2019-04-29.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 101

int D[MAX][MAX];
int n;
int *result;

int triggle_angle() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> D[i][j];
        }
    }

    result = D[n];
    for (int k = n - 1; k > 0; --k) {
        for (int i = 1; i < k; ++i) {
            result[i] = max(result[i], result[i + 1]) + D[k][i];
        }
    }
    cout << result[1] << endl;
}