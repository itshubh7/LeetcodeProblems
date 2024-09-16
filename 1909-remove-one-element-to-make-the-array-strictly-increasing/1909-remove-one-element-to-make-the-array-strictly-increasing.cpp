class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int i;
        for(i=1;i<nums.size()-1;i++){
            if(nums[i]<=nums[i-1]){
                if(nums[i+1]>nums[i-1]){
                    i++;
                    break;
                }
                if(i==1){
                    break;
                }
                if(nums[i-2]<nums[i]){
                    break;
                }
                return false;
            }
        }
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<=nums[j-1]){
                return false;
            }
        }
        return true;
    }
};