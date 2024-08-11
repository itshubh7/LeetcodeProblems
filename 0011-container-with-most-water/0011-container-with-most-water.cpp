class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxi = 0;
        
        while(start<end)
        {
            int calc = min(height[start], height[end]) * (end-start);
            maxi = max(maxi, calc);
            if(height[start]<height[end])
                start++;
            else end--;
        }
        
        return maxi;
    }
};