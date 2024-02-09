int numSquares(int n) {
    int perfect[101], index = 1, *dp = (int *)malloc(sizeof(int) * (n + 1));
    for( int i = 1;i <= sqrt(n); i++ ){
        perfect[i] = i*i; 
        dp[perfect[i]] = 1;
    }

    for(int i = 2; i <= n; i++ ){
        int min = INT_MAX;
        if( dp[i] != 1 ){
            for( int j = 1; j <= index; j++ ){
                int tmp = dp[i - perfect[j]] + dp[perfect[j]];
                if( min > tmp ){
                    min = tmp;
                }
            }
            dp[i] = min;
        }else{
            index++;
        }
    }
    return dp[n];
}
