class Solution {
public:
    vector<int>arr;
    vector<int>num;
    int last;
    Solution(vector<int>& nums) {
        last=nums.size()-1;
        arr=nums;
        num=nums;
        srand(time(0));
    }
    
    vector<int> reset() {
        num=arr;
        return num;
    }
    
    vector<int> shuffle() {
        int n=num.size();

        for(int i=n-1;i>=0;i--)
        {
            int r=rand()%(i+1);
            swap(num[r],num[i]);
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */