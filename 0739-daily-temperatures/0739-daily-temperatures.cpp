class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size());
        std::vector<int> rightHigher(temperatures.size());
        rightHigher[rightHigher.size() - 1] = -1;
        
        
        for (int i{ static_cast<int>(temperatures.size() - 2) }; i >= 0; --i) {
            int prevHigher{ i + 1 };
            while (rightHigher[prevHigher] != -1 && temperatures[prevHigher] <= temperatures[i]) {
                prevHigher = rightHigher[prevHigher];
            }
            
            if (temperatures[prevHigher] > temperatures[i]) {
                rightHigher[i] = prevHigher;
                result[i] = prevHigher - i;
            } else {
                rightHigher[i] = -1;
            }
        }
        
        return result;
    }
};