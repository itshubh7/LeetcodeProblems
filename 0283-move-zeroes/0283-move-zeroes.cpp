class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,k=0;
        for(i=0; i<nums.size(); i++)
        {
            if(nums[i]!=0)
            {
                nums[k]=nums[i];
                k++;
            }
        }
        for(i=k; i<nums.size(); i++)
        {
            nums[i]=0;
        }
        
    }
};