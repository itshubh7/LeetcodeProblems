class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long res = 0;

        if (n <= 2 * candidates) {
            sort(begin(costs), end(costs));
            for (int i = 0; i < k; i++) {
                res += costs[i];
            }
            return res;
        }

        priority_queue<int, vector<int>, greater<int>> start;
        priority_queue<int, vector<int>, greater<int>> end;
        vector<bool> visited(n, false);

        int i = 0, j = n - 1;

        while (i < candidates) {
            start.push(costs[i]);
            end.push(costs[j]);
            visited[i] = true;
            visited[j] = true;
            i++;
            j--;
        }

        while (k && !start.empty() && !end.empty()) {
            if (start.top() <= end.top()) {
                res += start.top();
                start.pop();
                if (i < n && !visited[i]) {
                    start.push(costs[i]);
                    visited[i] = true;
                    i++;
                }
            } else {
                res += end.top();
                end.pop();
                if (j >= 0 && !visited[j]) {
                    end.push(costs[j]);
                    visited[j] = true;
                    j--;
                }
            }
            k--;
        }

        while (k && !start.empty()) {
            res += start.top();
            start.pop();
            k--;
        }

        while (k && !end.empty()) {
            res += end.top();
            end.pop();
            k--;
        }

        return res;
    }
};