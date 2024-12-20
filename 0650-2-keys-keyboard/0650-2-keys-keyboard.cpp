class Solution {
public:
    int minSteps(int n) {
        int curr = 1;
        int copy = 0;
        int steps = 0;

        while(curr<n)
        {
            if((n-curr)%curr==0)
            {
                copy = curr;
                steps += 2;
            }
            else
            {
                steps += 1;
            }
            curr += copy;
        }

        return steps;
    }
};