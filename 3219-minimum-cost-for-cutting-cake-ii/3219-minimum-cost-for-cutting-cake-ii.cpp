class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        priority_queue<int> hCuts(horizontalCut.begin(), horizontalCut.end());
        priority_queue<int> vCuts(verticalCut.begin(), verticalCut.end());
        
        int h = 1; 
        int v = 1; 
        long long int cost = 0;
        
        while (!hCuts.empty() || !vCuts.empty() ) {
            if (vCuts.empty() || (!hCuts.empty() && hCuts.top() > vCuts.top())) {
                cost += hCuts.top() * v;
                hCuts.pop();
                h++;
            } else {
                cost += vCuts.top() * h;
                vCuts.pop();
                v++;
            }
        }
        
        return cost;
    }
};