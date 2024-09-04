class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(int i=0;i<obstacles.size();i++){
            string key=to_string(obstacles[i][0])+"_"+to_string(obstacles[i][1]);
            st.insert(key);
        }
        int x=0;
        int y=0;
        int maxi=0;
        pair<int,int>dir={0,1};
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-2){  // on turning left
                int a=dir.second;
                int b=dir.first;
                dir={-a,b}; // coordinates of dir is changed in this manner
            }else if(commands[i]==-1){ // on turning right
                int a=dir.second;
                int b=dir.first;
                dir={a,-b};  // coordinats of dir is changed in this manner
            }else{
                for(int j=0;j<commands[i];j++){
                    int new_x=x+dir.first;
                    int new_y=y+dir.second;
                    string new_key=to_string(new_x)+"_"+to_string(new_y);
                    if(st.find(new_key)!=st.end()) {break;}
                    x=new_x;
                    y=new_y;
                    maxi=max(maxi,(x*x+y*y));
                }
            }
            
        }
        return maxi;
    }
};