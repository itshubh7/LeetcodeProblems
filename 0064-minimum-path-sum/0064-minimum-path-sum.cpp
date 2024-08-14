class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>rec;
        
        int m=grid.size();
        int n=grid[0].size();
        
        rec.resize(m,vector<int>(n,0));
        rec[0][0]=grid[0][0];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    continue;
                }
                int to_add=INT_MAX;
                if(j>0)
                {
                    to_add=min(to_add,rec[i][j-1]); 
                }
                if(i>0)
                {
                    to_add=min(to_add,rec[i-1][j]);  
                }
                rec[i][j]=grid[i][j]+to_add;  
            }
        }
        return rec[m-1][n-1];
        
        
    }
};