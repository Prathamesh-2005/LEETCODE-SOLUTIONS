class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int all=0;
        for(int i=0;i<n;i++)
        {
            all^=nums[i];
        }
        // got xor then find the mask by using this xor 
        int cnt=0;

        while( (all & 1)==0)
        {
            all>>=1;
            cnt++;
        }
        int mask=1;
        mask<<=cnt;

        cout<<mask;
        int ans1{0};
        int ans2{0};
        for(int i=0;i<n;i++)
        {
            if(nums[i] & mask)
            {
                ans1^=nums[i];
            }else{
                ans2^=nums[i];
            }
        }
        return {ans1,ans2};
    }
};