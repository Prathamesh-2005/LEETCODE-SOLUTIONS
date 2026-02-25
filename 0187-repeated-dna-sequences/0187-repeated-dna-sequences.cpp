class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        if(n<10)
        {
            return {};
        }
        unordered_map<string,int>mp;
        vector<string>ans;
        int k=10;
        for(int i=0;i<=n-k;i++)
        {
            string str=s.substr(i,k);
            mp[str]++;
            if(mp[str]==2)
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};