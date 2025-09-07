class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1)
        {
            return {0};
        }
        vector<int>ans;

        for(int i=1;i<=n/2;i++)
        {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if(n & 1)
        {
            ans.push_back(0);
        }
        return ans;
    }
};