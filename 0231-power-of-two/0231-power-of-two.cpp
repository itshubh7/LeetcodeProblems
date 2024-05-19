class Solution {
public:
    bool isPowerOfTwo(int n) {
        float rem;
        if(n==1)
            return true;
        else if(n<=0)
            return false;
        else
        {
            while(n>1)
        {
            rem=n%2;
            if(rem==1)
                return false;
            n=n/2;
        }
        return true;
        }
        
    }
};