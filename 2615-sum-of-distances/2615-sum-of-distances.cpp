class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n, 0);
        unordered_map<int,ll> sum;
        unordered_map<int,ll> freq;

        for(int i=0;i<n;i++)
        {
            ll curr_sum=sum[nums[i]];
            ll frequ=freq[nums[i]];

            ans[i]+=(frequ*i-curr_sum);

            freq[nums[i]]+=1;
            sum[nums[i]]+=i;
        }

        freq.clear();
        sum.clear();
        for(int i=n-1;i>=0;i--)
        {
            ll curr_sum=sum[nums[i]];
            ll frequ=freq[nums[i]];

            ans[i]+=(curr_sum-frequ*i);

            freq[nums[i]]+=1;
            sum[nums[i]]+=i;
        }
        return ans;
    }
};
