class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int i,j, sum=0;
        for(i=0;i<s.length();i++)
        {
            for(j=0; j<s.length();j++)        
            {
                if(s[i]==t[j])
                {
                    sum+=abs(i-j);
                    continue;
                }
            }
        }
        return sum;
    }
};