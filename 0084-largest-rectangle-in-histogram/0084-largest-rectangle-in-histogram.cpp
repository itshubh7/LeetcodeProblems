class Solution {
public:
    vector<int> findnse(vector<int>& heights){
        vector<int> nse(heights.size());
        stack<int> st;
        for(int i = heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) nse[i] = heights.size();
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>& heights){
        vector<int> pse(heights.size());
        stack<int> st;
        for(int i = 0;i<heights.size();i++){
            while(!st.empty() && heights[i]<heights[st.top()]) st.pop();
            if(st.empty()) pse[i] = -1;
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = findpse(heights);
        vector<int> right = findnse(heights);
        long long maxarea = 0;
        long long area = 0;
        for(int i = 0;i<heights.size();i++){
            area = (right[i] - left[i] - 1)*heights[i];
            maxarea = max(maxarea,area);
        }
        return (int)maxarea;
    }
};