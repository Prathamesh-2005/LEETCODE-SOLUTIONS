class Solution {
public:
    vector<int> grayCode(int n) {
        int mx=1<<n;
        vector<int>ans(mx);
        for(int i=0;i<mx;i++)
        {
            ans[i]=(i^(i>>1));
        }
        return ans;
    }
};