class Solution {
public:
    int reverse(int x) {
        int val=x;
        if(x<0)
            val=abs(x);
        long rem,rev=0;
        while(val>0)
        {
            rem=val%10;
            rev=rev*10+rem;
            val/=10;
        }
        if(x<0)
            rev=0-rev;
        if(rev<INT_MIN || rev>INT_MAX)
            return 0;
        return rev;
    }
};