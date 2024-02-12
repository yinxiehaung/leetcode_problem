/*
    2, 3, 1, 2, 1, 1, 2
    dp[1] = 2
    dp[2] = max( dp[1], nums[1]);
    dp[3] = max( dp[1] + nums[2], dp[2]);
    dp[4] = max( dp[2] + nums[3], dp[3]);
    dp[5] = max( dp[3] + nums[4], dp[4]);
    dp[6] = max( dp[4] + nums[5], dp[5]);
*/
#define MAX(x,y) (x) > (y)?(x):(y)

int rob(int* nums, int numsSize) {
    if( numsSize < 2 ){
        return nums[0];
    }
    int dp[numsSize + 1];
    dp[1] = nums[0];
    dp[2] = MAX(nums[0], nums[1]);
    for( int i = 3; i <= numsSize; i++ ){
        dp[i] = MAX(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    return dp[numsSize];
}
