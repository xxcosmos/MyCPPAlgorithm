//
// Created by 张啸宇 on 2019-04-29.
//



int maxSubArray(int *nums, int numsSize) {
    int max = nums[0];
    int dp = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        dp = nums[i] > dp + nums[i] ? nums[i] : (dp + nums[i]);
        max = max > dp ? max : dp;
    }
    return max;
}
