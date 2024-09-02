class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        for(auto& i : chalk) sum+=i;
        k%=sum;
        for(int i=0; i<chalk.size(); i++)
        {
            if(k<chalk[i])  return i;
            else k-=chalk[i];
        }
        return 0;
    }
};