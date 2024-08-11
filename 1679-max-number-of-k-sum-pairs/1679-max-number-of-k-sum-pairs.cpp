class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        while(start < end)
        {
            if(nums[start]+nums[end]==k)
                count++, start++, end--;
            else if (nums[start]+nums[end] > k)
                end--;
            else start++;
        }
        return count;
    }
};