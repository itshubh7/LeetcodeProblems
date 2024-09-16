class Solution {
public:
    void solve(string& output, unordered_map<char,string>& mapping, vector<string>& ans, string digits, int i) {
        // Base case: if index i reaches the end of digits string
        if(i == digits.length()) {
            if(!output.empty()) { // If output is not empty, store it in ans
                ans.push_back(output);
            }
            return;
        }
        
        // Current digit
        char digit = digits[i];
        string mappedstring = mapping[digit];
        
        // Iterate through all the characters mapped to the current digit
        for(char ch : mappedstring) {
            output.push_back(ch); // Add current character to output
            solve(output, mapping, ans, digits, i + 1); // Recursive call with next index
            output.pop_back(); // Backtrack and remove the last character
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans; // Return an empty vector if digits is empty

        unordered_map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        string output = "";
        solve(output, mapping, ans, digits, 0); // Initial call to solve function
        return ans;
    }
};