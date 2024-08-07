class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
ll bsLow(const vi(int)&v, ll it, ll l, ll r){
    ll ans=-1;
    while(l<=r){
        ll m=l+((r-l)>>1);
        if(v[m]<it){
            l=m+1;
        }
        else{
            ans=m, r=m-1;
        }
    }
    return ans;
}

ll bsHigh(const vi(int)&v, ll it, ll l, ll r){
    ll ans=-1;
    while(l<=r){
        ll m=l+((r-l)>>1);
        if(v[m]>it){
            r=m-1;
        }
        else{
            ans=m, l=m+1;
        }
    }
    return ans;
}

long long countFairPairs(vector<int>&v, int low, int high) {
    sort(begin(v), end(v));
    ll ans=0, n=v.size();
    for(ll i=0;i<n;++i){
        ll l=low-v[i], r=high-v[i];
        ll lIn=bsLow(v, l, 0, i-1), rIn=bsHigh(v, r, 0, i-1);
        if(!(lIn==-1  || rIn==-1 || lIn>rIn)){
            ans+=rIn-lIn+1;
        }
    }
    return ans;
}
};