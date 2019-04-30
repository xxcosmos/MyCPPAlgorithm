//
// Created by 张啸宇 on 2019-04-28.
//
#include <iostream>
#include <cstring>
using namespace std;

int s[128];
int matrix[5][5] = {{5,  -1, -2, -1, -3},
                    {-1, 5,  -3, -2, -4},
                    {-2, -3, 5,  -2, -2},
                    {-1, -2, -2, 5,  -1},
                    {-3, -4, -2, -1, 0}};

int gene_funciton() {
    s['A'] = 0;
    s['C'] = 1;
    s['G'] = 2;
    s['T'] = 3;
    s['-'] = 4;
    int t;
    cin >> t;
    int m, n;
    string a, b;
    int f[101][101];
    while (t--) {
        memset(f, 0, sizeof(f));
        cin >> m >> a >> n >> b;

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 || j == 0) {
                    f[i][j] = 0;
                } else if (i == 0) {
                    f[i][j] = f[i][j - 1] + matrix[s['-']][s[b[j - 1]]];
                } else if (j == 0) {
                    f[i][j] = f[i - 1][j] + matrix[]
                }
            }
        }
    }

}