class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        vector<int>arr;
        for(int i=0,j=0; i<nums.size(); i++)
            if(nums[i]!=val){
                count++;
                nums[j]=nums[i];
                j++;
            }
        return count;
    }
};