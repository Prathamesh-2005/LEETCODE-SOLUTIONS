class Solution {
public:
    bool check(string &s,string& t)
    {
        int n=s.length();
        int m=t.length();

        if(m!=n)
        {
            return false;
        }
        unordered_map<char,int>mp;
        for(auto& c:s)
        {
            mp[c]++;
        }

        for(auto& c:t)
        {
            mp[c]--;

            if(mp[c]<0)
            {
                return false;
            }
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        int i = 1;

        while (i < words.size()) {
            string prev = words[i - 1]; 
            if (check(prev, words[i])) {
                words.erase(words.begin() + i);
            } else {
                i++;
            }
        }

        return words;

        return words;
    }
};