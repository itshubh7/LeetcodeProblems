class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char ch : s) {
            int cur = ch - 'a' + 1;
            sum += cur / 10 + cur % 10; 
        }
        
        while(--k > 0) {
            int new_sum = 0;
            while(sum > 0) {
                new_sum += sum % 10;
                sum /= 10;
            }
            sum = new_sum;
        }
        return sum;
    }
};
static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();