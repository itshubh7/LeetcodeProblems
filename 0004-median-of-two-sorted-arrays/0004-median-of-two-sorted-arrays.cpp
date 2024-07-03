class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int i=0; i<nums1.size(); i++)
                result.push_back(nums1[i]);
        for(int j=0; j<nums2.size(); j++)
                result.push_back(nums2[j]);
        sort(result.begin(), result.end());
        int size=result.size();
        double val;
        if(size%2==0)
            val=(result[size/2]+result[(size/2-1)])/2.0;
        else
            val=result[size/2];
        return val;
    }
};