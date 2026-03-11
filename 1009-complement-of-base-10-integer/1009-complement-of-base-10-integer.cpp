class Solution {
public:
    string binary(int n)
    {
        string ans="";

        while(n!=0)
        {
            ans+=((n%2)+'0');
            n/=2;
        }
        cout<<ans<<endl;
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int bitwiseComplement(int n) {
        string bin=binary(n);
        string curr="";
        if(n==0)
        {
            return 1;
        }
        for(auto& b:bin)
        {
            curr+=( b=='0' ? '1' : '0');
        }

        int j=0;
        long long ans=0;

        for(int i=curr.size()-1;i>=0;i--)
        {
            if(curr[i]=='1')
            {
                ans+=(1<<j);
            }
            j++;
        }
        cout<<ans<<endl;
        return ans;
    }
};