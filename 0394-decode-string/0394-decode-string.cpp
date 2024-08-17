class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack <char> st;
        for(int i = 0; i < n; i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else {
                string t;
                while(st.top() != '['){
                    t.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string a;
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    a.push_back(st.top());
                    st.pop();
                }
                reverse(a.begin(), a.end());

                int x = stoi(a);
               
                reverse(t.begin(), t.end());
                string temp;
                
                while(x--){
                    temp+=t;
                }
                for(int i = 0; i < temp.size(); i++){
                    st.push(temp[i]);
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;


    }
};