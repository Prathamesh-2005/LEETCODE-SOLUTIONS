class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<>>mn;
        map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        for(auto& [num,freq]:mp)
        {
            mn.push({freq,num});

            if(mn.size()>k)
            {
                mn.pop();
            }
        }

        vector<int>res;

        while(!mn.empty())
        {
            res.push_back(mn.top().second);
            mn.pop();

        }
        return res;
    }
};