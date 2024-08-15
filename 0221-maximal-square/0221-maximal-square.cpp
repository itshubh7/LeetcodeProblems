class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
         int m1=m.size(),n=m[0].size();
        vector<vector<int>> dp(m1,vector<int>(n,0));
        int ans = 0;
        bool pass = 0;
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                  dp[i][j]=m[i][j]-'0';
                  if(dp[i][j]==1) ans=1;
            }
        }
       
        for(int i = 1; i < m.size(); i++) {
            for (int j = 1; j < m[0].size(); j++) {
                if (dp[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i - 1][j] ,dp[i - 1][j - 1],dp[i][j - 1]});
                    ans = max(ans, (dp[i][j]) * (dp[i][j]));
                }
            }
        }


        return ans;
    }
};