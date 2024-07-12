class Solution {
public:
    int countMatches(vector<vector<string>>& items, string rulekey, string rulevalue) {
        int value,count=0;
        if(rulekey=="type")
            value=0;
        else if(rulekey=="color")
            value=1;
        else if(rulekey=="name")
            value=2;
        int len = items.size();
        for(int i=0; i<len; i++)
        {
            if(items[i][value]==rulevalue)
                count++;
        }
        return count;
    }
};