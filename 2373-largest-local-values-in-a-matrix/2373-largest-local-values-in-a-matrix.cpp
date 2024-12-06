class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();  
        vector<vector<int>> result(n - 2, vector<int>(n - 2)); 
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int local_max = 0;
                for (int x = i - 1; x <= i + 1; ++x) 
                    for (int y = j - 1; y <= j + 1; ++y) 
                        local_max = max(local_max, grid[x][y]);                
                result[i - 1][j - 1] = local_max;
            }
        }        
        return result;
    }
};