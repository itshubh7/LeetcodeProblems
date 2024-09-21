class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[50005][3];

        dp[0][1] = -prices[0];
        dp[0][2] = 0;

        for(int i=1;i<n;i++){
            dp[i][1] = max(dp[i-1][1], dp[i-1][2] - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i] - fee);
        }


        return dp[n-1][2];
    }
};