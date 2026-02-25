class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l = 0;
        int r = 0;
        int n = s.length();
        unordered_map<string,int>mp;
        vector<string>ans;
        while(r<n){
            if(r-l+1 == 10){
                string temp = s.substr(l,r-l+1);
                if(mp[temp] == 1){
                    ans.push_back(temp);
                }
                mp[temp]++;
               
                l++;
            }
            r++;
        }
        return ans;
    }
};