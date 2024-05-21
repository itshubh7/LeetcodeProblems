class Solution {
public:
    bool judgeCircle(string moves) {
        int count1=0, count2=0;
        int r=2,l=-2,u=1,d=-1;
        int n=moves.length();
        for(int i=0; i<n; i++)
        {
            if(moves[i]=='R')
                count1+=r;
            else if(moves[i]=='L')
                    count1+=l;
            else if(moves[i]=='U')
                    count2+=u;
            else if(moves[i]=='D')
                    count2+=d;
        }
        if(count1==0 && count2==0)
            return true;
        else
            return false;
    }
};