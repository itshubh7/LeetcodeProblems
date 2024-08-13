class Solution {
public:
    int n;
    vector<int>nums, path;
    vector<vector<int>> ans;
    void backtraking(int target, int start)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }
        for(int i=start;i<n;i++)
        {
            if (nums[i] > target) continue;
            path.push_back(nums[i]);
            backtraking(target - nums[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        nums = candidates;
        n = nums.size();
        backtraking(target, 0);
        return ans;
    }
};