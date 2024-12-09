pair<vector<int>, vector<bool>> pre_process(vector<vector<int>>& intervals) {
    int x_max = INT_MIN;
    for (auto &interval : intervals) {
        x_max = max(x_max, interval[1]);
    }

    vector<int> buckets(x_max + 1, 0);
    vector<bool> zero_length(x_max + 1, false);

    for (auto &interval : intervals) {
        int start = interval[0];
        int end = interval[1];
        if (start == end) {
            zero_length[start] = true;
        }
        buckets[start] -= 1; 
        buckets[end] += 1; 
    }

    return make_pair(buckets, zero_length);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto [bucks, zero_length] = pre_process(intervals);
        int bal = 0;
        vector<vector<int>> results;
        int start = 0, end = 0;
        int pointer = 0;
        int n = (int)bucks.size();

        while (pointer < n) {
            int prev_bal = bal;
            bal += bucks[pointer];
            if (bal == 0 && prev_bal == 0 && zero_length[pointer]) {
                results.push_back({pointer, pointer});
            }
            else if (bal < 0 && prev_bal == 0) {
                start = pointer;
            }
            else if (bal == 0 && prev_bal < 0) {
                end = pointer;
                results.push_back({start, end});
            }

            pointer++;
        }

        return results;
    }
};