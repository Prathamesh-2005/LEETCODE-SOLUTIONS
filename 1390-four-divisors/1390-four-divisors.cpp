class Solution {
public:
    int find(int num)
    {
        int ans=0;
        int cnt=0;
        for(int i=1;i<=(num);i++)
        {
            if(num%i==0)
            {
                ans+=i;
                cnt++;
            }
            if(cnt>4)
            {
                break;
            }
        }
        return (cnt==4 ? ans: 0);
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i]))
            {
                ans+=mp[nums[i]];
            }
            else{
                int div=find(nums[i]);
                mp[nums[i]]=div;
                ans+=div;
            }
        }
        return ans;
    }
};