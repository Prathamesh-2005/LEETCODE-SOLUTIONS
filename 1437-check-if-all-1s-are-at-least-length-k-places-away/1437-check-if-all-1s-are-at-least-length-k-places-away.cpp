class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool flag = false;
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (!flag && nums[i] == 1) {
                flag = true;
                cnt = 0; 
            }
            else if (flag && nums[i] == 1) {
                if (cnt < k) {   
                    return false;
                }
                cnt = 0;         
            }
            else if (flag && nums[i] == 0) {
                cnt++;   
            }
        }
        return true;
    }
};
