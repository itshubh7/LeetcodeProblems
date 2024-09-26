class Solution {
public: 
    int mergeintervals(vector<vector<int>>& points){
        int n=points.size();
        sort(points.begin(),points.end());
        vector<vector<int>>ans;
        int start=points[0][0];
        int end=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>end){
                ans.push_back({start,end});
                start=points[i][0];
                end=points[i][1];
            }
            else{
                if(points[i][1]<end){
                    end=points[i][1];
                }
            }
        }
        ans.push_back({start,end});
        return ans.size();
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        return mergeintervals(points);
    }
};