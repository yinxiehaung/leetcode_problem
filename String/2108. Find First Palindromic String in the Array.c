char* firstPalindrome(char** words, int wordsSize) {
    char *c = "";
    for( int i = 0; i < wordsSize; i++ ){
        bool isPalindromic = true;
        int start = 0, end = strlen(words[i]) - 1;
        for(; words[i][start] != 0 && end != start; start++, end--){
            if( words[i][start] != words[i][end] ){
                isPalindromic = false;
            }
        }
        if( isPalindromic ){
            return words[i];
        }
    }
    return c;
}
