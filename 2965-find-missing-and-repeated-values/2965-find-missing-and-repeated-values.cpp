class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr(2,0);
        int n=grid.size();
        int len = n*n;
        vector<int> freq(n*n+1,0);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                freq[grid[i][j]]++;
        }
        for(int i=1; i<=len; i++)
        {
            if(freq[i]==2)
                arr[0]=i;
            if(freq[i]==0)
                arr[1]=i;
        }
        return arr;
    }
};