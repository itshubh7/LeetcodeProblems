class Solution {
public:
    int findComplement(int num) {
        if(num==1)  return 0;
        
        string binary="";
        int remainder;
        while(num>0)
        {
            remainder=num % 2;
            binary+=to_string(remainder);
            num=num/2;
        }
        
        vector<int> comp;
        for(int i=0; i<binary.length(); i++)
        {
            if(binary[i]=='1')   comp.push_back(0);
            else    comp.push_back(1);
        }
            
        int ans=0;
        int exp=0;
        for(int i=0; i<comp.size(); i++)
        {
            ans+=pow(2,exp)*comp[i];
            exp++;
        }
        return ans;
    }
};