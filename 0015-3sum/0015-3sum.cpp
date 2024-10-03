class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        
        int n = nums.size();
        
        for(int i=0; i<n-1; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;

            int j = i+1;
            int k = n-1;
            while(j < k)
            {
                int total = nums[i]+nums[j]+nums[k];
                if(total > 0)
                    k--;
                else if (total < 0)
                    j++;
                else
                {
                    ret.push_back({nums[i], nums[j], nums[k]});

                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;

                    j++; k--;
                }
            }
        }
        
        return ret;
    }
};