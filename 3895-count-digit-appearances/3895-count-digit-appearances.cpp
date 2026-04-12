class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        
        int ans=0;
        for(auto& num:nums)
        {
            while(num!=0)
            {
                int dig=num%10;
                num/=10;
                if(dig==digit)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};