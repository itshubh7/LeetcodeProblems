class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();      
        int n = maze[0].size();   
        
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]}); 
        
        maze[entrance[0]][entrance[1]] = '+';
        
        int steps = 0;  
        while (!q.empty()) {
            int qSize = q.size();
            steps++;  
            
            for (int i = 0; i < qSize; i++) {
                auto [x, y] = q.front();  
                q.pop();
                
                for (auto dir : directions) {
                    int nx = x + dir[0]; 
                    int ny = y + dir[1]; 
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) {
                            return steps;
                        }
                        maze[nx][ny] = '+';
                        q.push({nx, ny}); 
                    }
                }
            }
        }
        return -1;
    }
};