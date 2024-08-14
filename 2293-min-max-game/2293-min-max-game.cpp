class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> temp(nums);
        
        if(nums.size()==1)
            return nums[0];
        bool mini = true;
        while(temp.size()!=1)
        {
            vector<int> res(temp.size()/2);
            int j=0;
            for(int i = 0; i<temp.size(); i+=2)
            {
                if(mini)
                {
                    res[j++] = min(temp[i], temp[i+1]);
                    mini = false;
                }
                else {res[j++] = max(temp[i], temp[i+1]);
                     mini = true;}
            }
            temp = res;
        }
        return temp[0];
    }
};