bool isPalindrome(int x) {
    if(x<0)
        return false;
    long long rev=0;
    long long val=x;
    while(val!=0)
    {
        int rem=val%10;
        rev=rev*10+rem;
        val/=10;
    }
    return (x==rev);

}