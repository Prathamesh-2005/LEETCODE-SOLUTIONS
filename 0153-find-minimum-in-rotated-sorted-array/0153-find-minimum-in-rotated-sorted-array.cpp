class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int n = nums.size();

        if (nums[l] < nums[h]) {
            return nums[l];
        }

        while (l <= h) {
            int m = l + (h - l) / 2;
            int prev = (m - 1 + n) % n; 
            int next = (m + 1) % n;     

            if (nums[m] <= nums[prev] && nums[m] <= nums[next]) {
                return nums[m];
            }

            if (nums[m] <= nums[h]) {
                h = m - 1; 
            } else {
                l = m + 1; 
            }
        }

       
        return 0;
    }
};
