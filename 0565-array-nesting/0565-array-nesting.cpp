class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int cnt=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int curr=-1;
            cnt=0;
            while(curr!=num && !visited[i])
            {
                visited[i]=true;
                i=nums[i];
                curr=nums[i];
                cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};