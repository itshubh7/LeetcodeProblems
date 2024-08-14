class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int high = 0;
        vector<int> res(n+1, 0);
        for(int i=1; i<n+1; i++)
        {
            res[i]=res[i-1]+gain[i-1];
            high = max(high, res[i]);
        }
        return high;
        
    }
};