int cmp(const void *arg1, const void *arg2){
    return *(int *)arg1 - *(int *)arg2;
}
int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    qsort((void *)tokens, tokensSize, sizeof(int), cmp);
    int score = 0, left = 0, right = tokensSize - 1;
    while(left < right && right > 0 && left < tokensSize){
        if(power >= tokens[left]){
            power -= tokens[left];
            score++;
            left++;
        }else if(score > 0 && power < tokens[left]){
            power += tokens[right--];
            score--;
        }else{
            left++;
        }
    }
    if(left == right && power >= tokens[left]){
        score++;
    }
    return score;
}
