class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
    
        int y=x;
        int sum=0;
        while(x!=0)
        {
            sum+=x%10;
            x/=10;
        }
        if(y%sum==0)
           return sum;
        return -1;
    }
};