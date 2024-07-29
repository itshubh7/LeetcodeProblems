class Solution {
public:
    int differenceOfSums(int n, int m) {
        long int sum1=0,sum2=0;
        for(int i=1; i<=n;i++)
        {
            if(i%m==0)
            {
                sum2+=i;
            }
            else
                sum1+=i;
        }
        return (sum1-sum2);
        
    }
};