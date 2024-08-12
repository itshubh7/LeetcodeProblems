class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> ma;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ma[nums[i]]++;
        }
        vector<int> unq;
        for (auto it : ma) {
            unq.push_back(it.first);
        }
        sort(unq.begin(), unq.end());
        vector<int> dp(unq.size() + 1);
        dp[0] = 0;
        dp[1] = ma[unq[0]] * unq[0];
        for (int i = 2; i <= unq.size(); i++) {
            if (unq[i - 2] < unq[i - 1] - 1) {
                dp[i] = dp[i - 1] + unq[i - 1] * ma[unq[i - 1]];
            } else {
                dp[i] = max(dp[i - 1], dp[i - 2] + unq[i - 1] * ma[unq[i - 1]]);
            }
        }
        return dp[unq.size()];
    }
};
