class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=INT_MIN;
        int curr=0;

        for(auto& g:gain)
        {
            curr+=g;
            ans=max(ans,curr);
        }
        return ans<0 ? 0:ans;
    }
};