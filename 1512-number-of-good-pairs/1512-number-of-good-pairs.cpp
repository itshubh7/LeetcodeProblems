class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int i,j,count=0;
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(nums[i]==nums[j] && i<j)
                    count++;
            }
        }
        return count;
    }
};