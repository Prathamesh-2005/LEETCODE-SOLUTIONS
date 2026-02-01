class Solution {
public:
    bool check(int num)
    {
        int zero=0;
        int ones=0;
        while(num>0)
        {
            if((num & 1))
            {
                ones++;
            }else{
                zero++;
            }
            num>>=1;
        }   

        if(ones==0 || zero==0)
        {
            return true;
        }
        return false;
    }
    int countMonobit(int n) {
        int ans=0;

        for(int i=0;i<=n;i++)
        {
            if(check(i))
            {
                ans++;
            }
        }
        return ans;
    }
};