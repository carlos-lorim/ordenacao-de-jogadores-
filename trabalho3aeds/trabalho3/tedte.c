comparar(const char *str1, const char *str2){
    while(*str1 && *str2){
        if (*str1 != *str2){
            return (*str1 - *str2);
        }
        *str1++;
    }
    return 0;
}