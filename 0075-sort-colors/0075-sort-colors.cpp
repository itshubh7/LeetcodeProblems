class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0, two=0, zero=0;
        for(auto num : nums)
            if(num==1)  one++;
            else if (num==2)    two++;
            else    zero++;
        int pos = 0;
        for(int i=0; i<zero; i++)
        {
            nums[i] = 0;
            pos++;
        }
        int val = pos;
        for(int i=pos; i<one+val; i++)
        {
            nums[i] = 1;
            pos++;
        }
        for(int i=pos; i<pos+two; i++)
        {
            nums[i] = 2;
        }
    }
};