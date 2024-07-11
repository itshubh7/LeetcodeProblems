char* truncateSentence(char* s, int k) {
    int i,count=0;
    for(i=0; i<strlen(s); i++)
    {
        if(s[i]==' ')
            count++;
        if(count==k)
             break;
    }
    s[i]='\0';
    return s;
}