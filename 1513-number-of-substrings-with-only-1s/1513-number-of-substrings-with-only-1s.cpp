#define mod 1000000007
class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        int n = s.length();
        int i = 0;       
        int j = 0;      

        while (j < n) {
            if (s[j] == '1') {
                j++;
            } else {
                int len = j - i;
                if (len > 0)
                    ans = (ans + (1LL * len * (len + 1) / 2)) % mod;
                
                j++;
                i = j; 
            }
        }

        int len = j - i;
        if (len > 0)
            ans = (ans + (1LL * len * (len + 1) / 2)) % mod;

        return ans % mod;
    }
};
