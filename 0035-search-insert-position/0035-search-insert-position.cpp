class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1)
        {
            if(target>nums[0])
                return 1;
            else return 0;
        }
        if(target<nums[n/2])
        {
            for(int i=0; i<n/2; i++ )
            {
                if(nums[i]==target)
                    return i;
                else if(target<nums[i])
                    return i;
                
            }
        }
        else if(target>nums[n/2])
        {
            for(int i=n/2; i<n; i++ )
            {
                if(nums[i]==target)
                    return i;
                else if(target<nums[i])
                    return i;
                
            }
            return n;
        }
        return n/2;
    }
};