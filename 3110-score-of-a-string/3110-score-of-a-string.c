int scoreOfString(char* s) {
    int len, sum=0, i=1;
    for(len =0; s[len]!='\0'; len++);
    while(i!=len)
    {
       if(s[i]>s[i-1]) 
           sum+=(s[i]-s[i-1]);
          else sum+=(s[i-1]-s[i]);
        i++;
    }
    return sum;
}