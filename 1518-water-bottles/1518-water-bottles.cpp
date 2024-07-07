class Solution {
public:
    int numWaterBottles(int num, int n) {
        int sum=num;
        while(num>=n)
        {
            int rem;
            rem=num%n;
            int div=num/n;
            num=num/n+rem;
            sum+=div;
            
        }
        return sum;
    }
};