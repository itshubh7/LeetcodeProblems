class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dir;
        int n = senate.length();
        for(int i=0; i<senate.length(); i++)
        {
            if(senate[i]=='R')
                rad.push(i);
            else    dir.push(i);
        }
         while (!rad.empty() && !dir.empty()) 
         {
            int r_index = rad.front();
            int d_index = dir.front();
            rad.pop();
            dir.pop();
            if (r_index < d_index) 
                rad.push(r_index + n); 
            else 
                dir.push(d_index + n);
            
        }
        
        return rad.empty() ? "Dire" : "Radiant";
    }
};