int minimumLength(char* s) {
    int min_len = strlen(s), prefix = 0, suffix = min_len - 1; 
    while(prefix < suffix && s[prefix] == s[suffix]){
        int next_prefix = prefix, next_suffix = suffix;
        while(s[next_prefix] == s[suffix] && next_prefix < suffix){
            next_prefix++;
        }
        while(s[next_suffix] == s[prefix] && next_suffix > prefix){
            next_suffix--;
        }
        min_len -= next_prefix - prefix + suffix - next_suffix;
        prefix = next_prefix;
        suffix = next_suffix;
    }
    return min_len < 0?0:min_len;
}
