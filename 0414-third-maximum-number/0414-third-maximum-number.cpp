class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> arr(st.begin(), st.end());
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n<=2)    return arr[n-1];
        return arr[n-3];
    }
};