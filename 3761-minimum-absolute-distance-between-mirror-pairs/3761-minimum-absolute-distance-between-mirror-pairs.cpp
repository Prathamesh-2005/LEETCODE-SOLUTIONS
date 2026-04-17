class Solution {
public:
    int reverseNum(int num)
    {
        int rev = 0;
        while(num > 0)
        {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        for(int i = 0; i < n; i++)
        {
            int rev = reverseNum(nums[i]);

            if(mp.count(rev))
            {
                auto& vec=mp[rev];
                auto idx=upper_bound(vec.begin(),vec.end(),i);

                if(idx!=vec.end())
                {
                    ans=min(ans,abs(*idx-i));
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};