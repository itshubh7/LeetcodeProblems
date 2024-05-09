class Solution {
public:
    int strStr(string haystack, string needle) {
        int i;
        if(haystack.length() < needle.length())
            return -1;
        else{
            for(i=0; i<=(haystack.length() - needle.length()); i++)
            {
                int j;
                for(j=0; j<needle.length(); j++)
                {
                    if(haystack[i+j]!=needle[j])
                        break;
                }
                if(needle.length() == j)
                {
                    return i;
                }
            }
        
        return -1;}
    }
};