class Solution
{
public:
    int countStableSubsequences(vector<int> &nums)
    {
        const int mod = 1e9 + 7;
        int n = nums.size();
        long odd = 0, even = 0, odd_odd = 0, even_even = 0;

        for (int i : nums)
        {
            if (i & 1) 
            {
                odd_odd += odd;

                odd++; 


                odd += even;
                odd += even_even;

                odd_odd %= mod;
                odd %= mod;
            }
            else 
            {
                even_even += even;

                even++;

                even += odd;
                even += odd_odd;

                even_even %= mod;
                even %= mod;
            }
        }
        return (odd + even + odd_odd + even_even) % mod;
    }
};