class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mn=INT_MAX;

        for(int i=1;i<n;i++)
        {
            mn=min(mn,arr[i]-arr[i-1]);
        }

        for(int i=1;i<n;i++)
        {
            int diff=arr[i]-arr[i-1];
            if(diff==mn)
            {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};