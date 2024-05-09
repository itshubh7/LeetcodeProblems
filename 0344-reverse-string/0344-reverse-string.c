void reverseString(char* s, int sSize) {
    int i;
    for(i = 0; i<sSize/2; i++)
    {
        s[i]=s[i]^s[sSize-1-i];
        s[sSize-1-i]=s[i]^s[sSize-1-i];
        s[i]=s[i]^s[sSize-1-i];
    }
}