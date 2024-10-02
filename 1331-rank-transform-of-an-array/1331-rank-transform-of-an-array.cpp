class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int> arr2(arr);
        sort(arr2.begin(),arr2.end());
        unordered_map<int,int> map{};
        int rank = 1;
        for (int item: arr2) {
            if (!map.contains(item)) {
                map[item] = rank;
                rank += 1;
            }
        }
        vector<int> result{};
        for (int item : arr) { result.push_back(map[item]); }
        return result;
    }
};