
class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        if (m == 1 || n == 1) return A[0][0];

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MAX));
        int ans = INT_MAX;

        for (int i = 0; i < A.size(); ++i) {
            ans = std::min(ans, minFallingPathSum(A, 0, i, dp));
        }

        return ans;
    }

    int minFallingPathSum(std::vector<std::vector<int>>& A, int row, int col, std::vector<std::vector<int>>& dp) {
        int m = A.size();
        int n = A[0].size();

        if (dp[row][col] != INT_MAX) return dp[row][col];

        if (row == m - 1)
            return dp[row][col] = A[row][col];

        int left = INT_MAX, right = INT_MAX;

        if (col > 0)
            left = minFallingPathSum(A, row + 1, col - 1, dp);

        int straight = minFallingPathSum(A, row + 1, col, dp);

        if (col < n - 1)
            right = minFallingPathSum(A, row + 1, col + 1, dp);

        dp[row][col] = std::min(left, std::min(straight, right)) + A[row][col];

        return dp[row][col];
    }
};
