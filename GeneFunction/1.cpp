//
// Created by 张啸宇 on 2019-04-29.
//


#include <iostream>
#include<cstring>
#include<map>

using namespace std;

int s[128];
int arr[5][5] = {{5,  -1, -2, -1, -3},
                 {-1, 5,  -3, -2, -4},
                 {-2, -3, 5,  -2, -2},
                 {-1, -2, -2, 5,  -1},
                 {-3, -4, -2, -1, 0}};


int gene_function() {
    s['A'] = 0;
    s['C'] = 1;
    s['G'] = 2;
    s['T'] = 3;
    s['-'] = 4;
    int t, j, k, m, n;
    int f1, f2, f3;
    int f[101][101];

    string a, b;
    cin >> t;
    while (t--) {
        j = k = 0;
        memset(f, 0, sizeof(f));
        cin >> m >> a;
        cin >> n >> b;
        for (j = 0; j <= m; j++) {
            for (k = 0; k <= n; k++) {
                if (j == 0 && k == 0)
                    f[j][k] = 0;
                else if (j == 0) {
                    f[j][k] = f[j][k - 1] + arr[s['-']][s[b[k - 1]]];
                } else if (k == 0)
                    f[j][k] = f[j - 1][k] + arr[s[a[j - 1]]][s['-']];
                else {
                    f1 = f[j][k - 1] + arr[s['-']][s[b[k - 1]]];
                    f2 = f[j - 1][k] + arr[s[a[j - 1]]][s['-']];
                    f3 = f[j - 1][k - 1] + arr[s[a[j - 1]]][s[b[k - 1]]];
                    f[j][k] = max(f1, max(f2, f3));
                }
            }
        }
        cout << f[m][n] << endl;
    }
    return 0;
}