class Solution {
public:
    int maxVowels(string s, int k){
        int c=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u') c++;
        }

        int mx=c;
        for(int i=k;i<s.size();i++){
            if(s[i-k]=='a' or s[i-k]=='o' or s[i-k]=='i' or s[i-k]=='e' or s[i-k]=='u') c--;
            
            if(s[i]=='a' or s[i]=='o' or s[i]=='i' or s[i]=='e' or s[i]=='u') c++;
    
            mx=max(mx,c);
        }
        return mx;
    }
};