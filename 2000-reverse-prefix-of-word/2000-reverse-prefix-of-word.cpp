class Solution {
public:
    string reversePrefix(string word, char ch) {
        string str;
        int pos=-1;
        for(int i=0; i<word.length(); i++)
            if(word[i]==ch)
            {
                pos=i;
                break;
            }
        if (pos!=-1)
        {
            for(int i=pos; i>=0; i--)
            {
                str+=word[i];
            }
            for(int i=pos+1; i<word.length(); i++)
            {
                str+=word[i];
            }
            return str;
        }
        return word;
    }
};