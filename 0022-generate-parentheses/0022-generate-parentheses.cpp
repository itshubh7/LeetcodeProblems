class Solution {
public:
    void helper(vector<string>& ans, string output, int n, int op, int cl, int size) {
        if (n == 0) {
            ans.push_back(output);
        }
        if (cl < op && cl < size) {
            helper(ans, output + ')', n - 1, op, cl + 1, size);  
        }
        if (op < size) {
            helper(ans, output + '(', n - 1, op + 1, cl, size);  
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", n * 2, 0, 0, n);
        return ans; 
    }
};