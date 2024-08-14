class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int stall = 0;
        int maximum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                stall = 0;
            else
            {
                stall++;
                maximum = max(maximum, stall); 
            }
        }
        return maximum;
    }
};