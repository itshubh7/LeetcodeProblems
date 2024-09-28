class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = INT_MIN, sum = 0;
        priority_queue<int> pq;
        vector<pair<int, int>> vec;
        unordered_map<int, int> mp;

        for(int i = 0;i < nums1.size();i++){
            vec.push_back({nums2[i], nums1[i]});
        }

        sort(vec.begin(), vec.end());//2.

        for(int i = 0;i < vec.size();i++){
            pq.push(vec[i].second);//3.
            mp[vec[i].second]++;//4.
        }

        for(int i = 1;i < k;i++){
            sum += pq.top();
            mp[pq.top()]--;
            pq.pop();
        }

        for(int i = 0;i < vec.size() - k + 1;i++){
            if(mp[vec[i].second] != 0){//6.
                if(ans < (sum + vec[i].second) * vec[i].first){
                    ans = (sum + vec[i].second) * vec[i].first;
                }
                mp[vec[i].second]--;
            }else{//7.
                while(mp[pq.top()] == 0) pq.pop();
                sum += pq.top();
                mp[pq.top()]--;
                pq.pop();
                if(ans < sum * vec[i].first) ans = sum * vec[i].first;
                sum -= vec[i].second;
            }
        }

        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();