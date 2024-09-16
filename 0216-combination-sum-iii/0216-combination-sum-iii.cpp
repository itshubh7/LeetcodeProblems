class Solution {
public:

    vector<vector<int>> ans;
    vector<int> v;
    void rec(int n, int k, int last){
        if (n < 0 || k < 0) return;
        if (n == 0){
            if (k == 0) ans.push_back(v);
            return;
        }
        for (int i = last+1; i <= 9; i++){
            v.push_back(i);
            rec(n-i, k-1, i);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        rec(n, k, 0);
        return ans;
    }
};