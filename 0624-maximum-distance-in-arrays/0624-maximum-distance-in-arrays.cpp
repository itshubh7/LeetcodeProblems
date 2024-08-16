class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max1 = arrays[0][0];
        int min1 = arrays[0].back();
        int dis = 0;
        
        for(int i=0; i<arrays.size(); i++)
        {
            dis = max(dis, arrays[i].back()-min1);
            dis = max(dis, max1-arrays[i][0]);
            min1 = min(min1, arrays[i][0]);
            max1 = max(max1, arrays[i].back());
        }
        return dis;
        
    }
};