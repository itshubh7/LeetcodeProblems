class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int c=0, l=0, r=0, ans=INT_MIN;

        while(l<nums.size() && r<nums.size()) {
            if((nums[r]==0 && c==0) || nums[r]==1){
                if(nums[r]==0)
                    c=1;
                r++;
            }
            else {
                ans=max(ans, r-l-1);
                if(nums[l]==0)
                    c=0;
                l++;
            }
        }

        ans=max(ans, r-l-1);
        return ans;
    }
};