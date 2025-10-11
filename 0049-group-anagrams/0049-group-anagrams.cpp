class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          vector<vector<string>>ans;
          unordered_map<string,vector<string>>mp;

          for(auto word:strs)
          {
            string str=word;
            sort(str.begin(),str.end());
            mp[str].push_back(word);
          }

          for(auto& m:mp)
          {
            ans.push_back(m.second);
          }

          return ans;
        
    }
};