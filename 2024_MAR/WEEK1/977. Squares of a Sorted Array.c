int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    for(int i = 0; i < numsSize; i++){
        nums[i] *= nums[i];
    }
    //qsort((void *)nums, numsSize, sizeof(int), cmp);
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int i = numsSize - 1, l = 0, r = i;
    while(l <= r){
        if(nums[l] > nums[r]){
            ret[i--] = nums[l++];
        }else{
            ret[i--] = nums[r--];
        }
    }
    //memcpy(ret, nums, sizeof(int) * numsSize);
    return ret;
}
