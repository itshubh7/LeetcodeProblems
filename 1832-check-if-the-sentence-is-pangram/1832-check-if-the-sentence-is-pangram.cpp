class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n=sentence.length();
        if(n<26)
            return false;
        else
        {
            bool avail[26]={0};
            for(int i=0; i<n; i++)
            {
                int pos=sentence.at(i) - 'a'; 
                avail[pos]=1;
            }
            for(int i=0; i<26; i++)
                if(avail[i]!=1)
                    return false;
            return true;
        }
    }
};