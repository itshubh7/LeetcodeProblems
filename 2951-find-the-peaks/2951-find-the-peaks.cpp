class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> peak;
        int n = mountain.size();
        for(int i=1; i<n-1; i++)
        {
            if(mountain[i]>mountain[i+1] && mountain[i]>mountain[i-1])
            {
                peak.push_back(i);
            }
        }
        return peak;
    }
};