class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
    for(int i=0 ; i<n-1 ;i++){
        for(int j=0; j<n-i-1;j++){
            if(indices[j]>indices[j+1]){
                swap(s[j],s[j+1]);
                swap(indices[j],indices[j+1]);
            }
        }
    }
    return s;
    }
};