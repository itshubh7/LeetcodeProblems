class Solution {
public:
    bool isAnagram(string s, string t) {
        long int m = s.length();
        long int n = t.length();
        if(n!=m)
            return false;
        else
        {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return (s==t);
        }
    }
};