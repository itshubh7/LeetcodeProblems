class Solution {
public:
    int solveUsingRec(string &a, string& b, int i , int j){
        if(i>=a.length()){
            return b.length()-j;
        }
        if(j>=b.length()){
            return a.length()-i;
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=0 + solveUsingRec(a,b,i+1,j+1);
        }
        else{
            int replace=1+solveUsingRec(a,b,i+1,j+1);
            int insert=1+solveUsingRec(a,b,i,j+1);
            int remove=1+solveUsingRec(a,b,i+1,j);
             ans=min(insert,min(replace,remove));
        }
        return ans ;
       
    }

    int solveUsingMemo(string & a, string & b,int i,int j,vector<vector<int>> &dp){
         if(i>=a.length()){
            return b.length()-j;
        }
        if(j>=b.length()){
            return a.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=0 +solveUsingMemo(a,b,i+1,j+1,dp);
        }
        else{
            int replace=1+solveUsingMemo(a,b,i+1,j+1,dp);
            int insert=1+solveUsingMemo(a,b,i,j+1,dp);
            int remove=1+solveUsingMemo(a,b,i+1,j,dp);
            ans=min(insert,min(replace,remove));
        }
        dp[i][j]=ans;
        return dp[i][j];
       
    }

    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        int ans=solveUsingMemo(word1,word2,i,j,dp);
        return ans;
    }
};