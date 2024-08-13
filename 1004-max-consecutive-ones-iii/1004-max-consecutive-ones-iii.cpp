bool isPossible(vector<int> &nums, int k, int mid)
{
    int c_0 = 0;
    for (int i = 0; i < mid; i++)
    {
        if (nums[i] == 0)
        {
            c_0++;
        }
    }
    if (c_0 <= k)
        return true;

    for (int i = 1; i < (nums.size() - mid + 1); i++)
    {
        if (nums[i - 1] == 0)
            c_0--;
        if (nums[i + mid - 1] == 0)
            c_0++;

        if (c_0 <= k)
        {

            return true;
        }
    }

    return false;
}

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int len = nums.size();
        int low = 0, result = 0;
        int high = len;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, k, mid))
            {
                result = max(result, mid);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
    }
};