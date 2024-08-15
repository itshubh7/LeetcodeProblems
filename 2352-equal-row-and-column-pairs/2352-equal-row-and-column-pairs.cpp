class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<string> row;
        vector<string> col;

        for (int i = 0; i < n; i++) {
            string s1 = "";
            string s2 = "";
            for (int j = 0; j < n; j++) {
                s1 += to_string(grid[i][j]) + " ";
                s2 += to_string(grid[j][i]) + " ";
            }
            row.push_back(s1);
            col.push_back(s2);
        }

        int pair = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == col[j])
                    pair++;
            }
        }

        return pair;
    }
};