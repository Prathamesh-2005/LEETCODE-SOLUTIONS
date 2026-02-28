class Solution {
public:
    typedef long long ll;
    string solve(int num)
    {
        string ans="";
        while(num!=0)
        {
            ans+=((num%2)+'0');
            num/=2;
        }
        cout<<ans<<endl;
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int concatenatedBinary(int n) {
        int mod=1e9+7;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            string curr=solve(i);
            int n=curr.length();
            ans=((ans<<n)+i)%mod;
        }
        return ans%mod;
    }
};