class Solution {
public:
    int n;
    bool solve(vector<int>& arr,int idx,vector<bool>& vis)
    {
        n=arr.size();
        if(idx<0 || idx>=n)
        {
            return false;
        }

        if(arr[idx]==0)
        {
            return true;
        }

        if(vis[idx])
        {
            return false;
        }
        vis[idx]=true;
        bool right=solve(arr,idx+arr[idx],vis);
        bool left=solve(arr,idx-arr[idx],vis);

        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>vis(arr.size(),false);
        return solve(arr,start,vis);
    }
};