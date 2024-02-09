/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp( const void *arg1, const void *arg2 ){
    return (*(int *)arg2 - *(int *)arg1);
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if( numsSize == 1 ){
        *returnSize = numsSize;
        return nums;
    }
    qsort((void *)nums, numsSize, sizeof(int), cmp);
    
    int *dp = (int *)malloc(sizeof(int) * numsSize), max = 0, sec_max = 0;
    int *next_div = (int *)calloc(sizeof(int), numsSize);
    
    for( int i = 0; i < numsSize; i++ ){
        dp[i] = 1;
    }
  
    for( int i = 1; i < numsSize; i++ ){
        for( int j = i - 1; j >= 0; j-- ){
            if( nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1 ){
                dp[i] = dp[j] + 1;
                next_div[i] = j;
                if( dp[max] < dp[i]){
                    max = i;
                }
            }
        }
    }
  
  int *ret = (int *)malloc(sizeof(int) * dp[max] + 1), index = 0;
    *returnSize = dp[max];
  
    while( index < *returnSize){
        ret[index++] = nums[max];
        max = next_div[max];
    }
    return ret;
}
