char* maximumOddBinaryNumber(char* s){
    int length = strlen(s), freq_0 = 0, freq_1 = 0;
    char *max_odd_bin = (char *)malloc(sizeof(char) * length + 1);
    for(int i = 0; i < length; i++){
        max_odd_bin[i] = '0';
        if(s[i] == '1'){
            freq_1++;
        }else{
            freq_0++;
        }   
    }
    for(int i = 0; i < freq_1 - 1; i++){
        max_odd_bin[i] = '1';
    }
    for(int i = freq_1; i <= freq_0; i++){
        max_odd_bin[i] = '0';
    }
    max_odd_bin[length - 1] = '1';
    max_odd_bin[length] = '\0';
    return max_odd_bin;
}
