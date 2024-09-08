class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int len = 0;
        for(int i = 0; i<m; i++)    nums1[len++] = nums1[i];
        for(int i = 0; i<n; i++)    nums1[len++] = nums2[i];
        sort(nums1.begin(), nums1.end());
    }
};