int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize], ret = INT_MAX;
    dp[0] = cost[0];
    dp[1] = cost[1];
    for( int i = 2; i < costSize ; i++ ){
        dp[i] = cost[i];
        dp[i] += dp[i - 1] > dp[i - 2] ? dp[i - 2]:dp[i - 1];
    }
    return dp[costSize - 1] > dp[costSize - 2] ? dp[costSize - 2]:dp[costSize - 1];
}
