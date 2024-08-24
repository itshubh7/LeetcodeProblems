class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<nums[i-1])
            {
                start++;
                break;
            }
            start++;
        }
        if(target<nums[0])
        {
            for(int i=start; i<nums.size(); i++)
                if(nums[i]==target) return true;
        }
        else
        {
            for(int i=0; i<=start; i++)
                if(nums[i]==target) return true;
        }
        return false;
    }
};