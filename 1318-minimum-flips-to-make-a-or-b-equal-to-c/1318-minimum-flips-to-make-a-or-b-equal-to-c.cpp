class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int> bits_a(32,0), bits_b(32,0), bits_c(32,0);
        int i = 0;
        while(a) {
            bits_a[i++] = a%2;
            a = a/2;
        }
        i = 0;
        while(b) {
            bits_b[i++] = b%2;
            b = b/2;
        }
        i = 0;
        while(c) {
            bits_c[i++] = c%2;
            c = c/2;
        }

        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(bits_c[i] == 1) {
                if(bits_a[i] + bits_b[i] == 0) ans++;
            }
            if(bits_c[i] == 0) {
                if(bits_a[i] + bits_b[i] > 0) ans += bits_a[i]+bits_b[i];
            }
        }
        return ans;
    }
};