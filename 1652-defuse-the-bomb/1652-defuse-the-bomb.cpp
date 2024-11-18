class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
         vector<int>ans(code.size(),0);
        if(!k) return ans;
        int tempu=0;
       int s=(k<0)?code.size()+k:1;
       int e=(k<0)?code.size()-1:k;
        for(int i=s;i<=e;i++) tempu+=code[i];
        for(int i=0;i<code.size();i++){
            ans[i]=tempu;
            tempu-=code[(s+i)%code.size()];
            tempu+=code[(e+i+1)%code.size()];
        }
        return ans;
    }
};