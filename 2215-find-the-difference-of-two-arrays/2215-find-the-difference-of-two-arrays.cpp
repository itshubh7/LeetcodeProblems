class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m1;
        map<int,int>m2;
        vector<vector<int>>v;
        for(int i:nums1){
            m1[i]++;
        }
        for(int i:nums2){
            m2[i]++;
        }
        vector<int>v1;
        for(int i=0;i<nums1.size();i++){
            if(m2[nums1[i]]==0 && find(v1.begin(),v1.end(),nums1[i]) == v1.end()){
                v1.push_back(nums1[i]);
            }
        }
        v.push_back(v1);
        v1.clear();
        for(int i=0;i<nums2.size();i++){
            if(m1[nums2[i]]==0 && find(v1.begin(),v1.end(),nums2[i]) == v1.end()){
                v1.push_back(nums2[i]);
            }
        }
        v.push_back(v1);
        return v;
    }
};