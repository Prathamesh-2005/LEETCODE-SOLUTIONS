class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long,int>mp;

        for(auto& num:nums)
        {
            mp[num]++;
        }

        int ans=INT_MIN;

        for(auto& [num,freq]:mp)
        {
            long long x=num;
            int cnt=0;

            while(mp.find(x)!=mp.end() && mp[x])
            {
                if(x==1)
                {
                    cnt+=mp[x];
                }
                else if(mp[x]>=2)
                {
                    cnt+=2;
                }else if(mp[x]==1){
                    cnt+=1;
                    break;
                }
                mp[x]=0;
                if(x>1e5)
                {
                    break;
                }
                x=x*x;
            }
            ans=max(ans,cnt-(cnt%2==0));
        }
        return ans;
    }
};