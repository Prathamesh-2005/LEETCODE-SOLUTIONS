class Solution {
public:
    string solve(string& str)
    {
        int n=str.length();
        vector<int>arr(26,0);

        for(int i=0;i<n;i++)
        {
            arr[str[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
                ans+=string(arr[i],i+'a');
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          vector<vector<string>>ans;
          unordered_map<string,vector<string>>mp;
          int n=strs.size();

          for(int i=0;i<n;i++)
          {
             string word=strs[i];
             string str=solve(word);
             mp[str].push_back(word);
          }
          for(auto& m:mp)
          {
            ans.push_back(m.second);
          }

          return ans;
        
    }
};