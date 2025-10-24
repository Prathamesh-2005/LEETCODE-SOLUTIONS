class Solution {
public:
    bool balance(int i)
    {
        vector<int>mp(10,0);
        
        while(i!=0)
        {
            int digit=i%10;
            i/=10;
            mp[digit]++;
        }

        for (int i = 0; i < 10; i++)
        {
            if (mp[i] != 0 && mp[i] != i)
                return false;
        }

        return true;
    }
    int nextBeautifulNumber(int n) {
        if(n>=666666)
        {
            return 1224444;
        }
        for(int i=n+1;i<=1e6;i++)
        {
            if(balance(i))
            {
                return i;
            }
        }

        return -1;
    }
};