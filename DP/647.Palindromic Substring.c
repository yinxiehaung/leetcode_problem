int countSubstrings(char* s) {
    int length = strlen(s), res = 0;
    bool dp[length][length];
    for( int i = 0; i < length; i++ ){
        for( int j = 0; j < length; j++ ){
            if( j == i ){
                dp[i][j] = true;
            }else{
                dp[i][j] = false;
            }
        }
    }
    
    for( int len = 1; len <= length; len++ ){
        for( int i = 0; i <= length - len; i++ ){
            int j = i + len - 1;
            if( s[i] == s[j] ){
                if( j - i <= 2 || dp[i + 1][j - 1] ){
                    dp[i][j] = true;
                    res++;
                }
            }
        }
    }
    return res;
}
