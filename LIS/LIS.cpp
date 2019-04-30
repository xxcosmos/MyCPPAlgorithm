//
// Created by 张啸宇 on 2019-04-28.
//

#include <iostream>

using namespace std;

/* 最长递增子序列 LIS
 * 设数组长度不超过 30
 * DP
*/

int dp[31]; /* dp[i]记录到[0,i]数组的LIS */
int length;

int LIS(const int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if (dp[i] > length) {
                    length = dp[i];
                }
            }
        }
    }
    return length;
}

/* 输出LIS */
void outputLIS(int *arr, int index) {
    bool isLIS = false;
    if (index < 0 || length == 0) {
        return;
    }
    if (dp[index] == length) {
        length--;
        isLIS = true;
    }

    outputLIS(arr, --index);

    if (isLIS) {
        printf("%d ", arr[index + 1]);
    }
}