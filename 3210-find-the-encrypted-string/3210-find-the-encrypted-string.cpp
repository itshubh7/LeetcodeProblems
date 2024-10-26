class Solution {
public:
    string getEncryptedString(string s, int k) {
        int len = s.length();
        if (len==1)
                return s;
        k%=len;
        reverse(s.begin(), s.end());
        reverse(s.begin()+len-k, s.end());
        reverse(s.begin(),s.begin()+len-k);
        
        
        return s;
    }
};