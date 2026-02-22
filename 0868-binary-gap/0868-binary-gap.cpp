class Solution {
public:
    string find(int n)
    {
        string ans="";

        while(n!=0)
        {
            int rem=n%2;
            ans+=(to_string(rem));
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int binaryGap(int n) {
        string str=find(n);
        cout<<str;
        int m=str.size();
        int first=-1;
        int second=-1;
        int ans=-1;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            if(str[i]=='1')
            {
                if(first==-1)
                {
                    first=i;
                }else if(second==-1 && first!=-1){
                    second=i;
                    ans=max(ans,second-first);
                    first=second;
                    second=-1;
                }
                cnt++;
            }
        }
        if(cnt==1)
        {
            return 0;
        }
        return ans;
    }
};