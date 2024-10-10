class Solution {
public:
    int lengthOfLastWord(string s) {
        int len  = s.size()-1;
        int result = 0;
        while(s[len]==' ')  len--;
        while(len >= 0 && s[len]!=' ')
        {
            len--;
            result++;
        }
        return result;
    }
};