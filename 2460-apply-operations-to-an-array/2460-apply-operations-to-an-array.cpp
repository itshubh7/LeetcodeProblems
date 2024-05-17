class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i;
        for(i=1; i<nums.size(); i++)
        {
            if(nums[i]==nums[i-1])
            {
                nums[i-1] *= 2;
                nums[i] = 0;
            }
        }
        int k=0;
        for(i=0; i<nums.size(); i++)
        {
            if(nums[i]!=0)
            {
                nums[k]=nums[i];
                k++;
            }
        }
        for(i=k; i<nums.size(); i++)
        {
            nums[i]=0;
        }
        
        return nums;
    }
};