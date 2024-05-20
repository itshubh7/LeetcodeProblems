class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int i, j, n=nums.size(), count =0;
        if(n==1)
           return count; 
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(nums[i]+nums[j]<target)
                    count++;
            }
        }
        return count;
    }
};