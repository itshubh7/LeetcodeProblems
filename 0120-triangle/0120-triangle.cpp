class Solution {
public:
    int mm;
    int t[201][201];
    vector<vector<int>> nums;

    int fun(int i, int j) {
        if (i == mm - 1) return nums[i][j]; 
        if (t[i][j] != -1) return t[i][j];
        int vertical = fun(i + 1, j); 
        int diagonal = fun(i + 1, j + 1); 
        return t[i][j] = nums[i][j] + min(vertical, diagonal); 
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        mm = triangle.size();
        nums = triangle;
        memset(t, -1, sizeof(t));
        return fun(0, 0); 
    }
};