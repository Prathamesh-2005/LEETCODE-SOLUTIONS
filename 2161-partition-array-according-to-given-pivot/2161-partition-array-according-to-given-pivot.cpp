class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        vector<int>before;
        vector<int>after;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==pivot)
            {
                cnt++;
            }
            if(nums[i]<pivot)
            {
                before.push_back(nums[i]);
            }
        }

       

       // before.push_back(pivot);

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>pivot)
            {
                after.push_back(nums[i]);
            }
        }
        for(auto& n:before)
        {
            ans.push_back(n);

        }
        while(cnt!=0)
        {
            ans.push_back(pivot);
            cnt--;
        }

      for(auto& n:after)
        {
            ans.push_back(n);
        }
        return ans;
    }
};