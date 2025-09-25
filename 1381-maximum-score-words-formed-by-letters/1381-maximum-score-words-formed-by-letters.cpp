class Solution {
public:
    int n;
    void solve(int idx,vector<string>& words,vector<int>& score,vector<int>& mp,int& ans,int curr)
    {
        ans=max(ans,curr);

        if(idx>=n)
        {
            return ;
        }

        vector<int>temp=mp;
        int j=0;
        int sc=0;
        for(;j<words[idx].length();j++)
        {
            char ch=words[idx][j];
            temp[ch-'a']--;
            sc+=score[ch-'a'];
            if(temp[ch-'a']<0)
            {
                break;
            }
        }

        if(j==words[idx].length())
        {
            solve(idx+1,words,score,temp,ans,curr+sc);
        }

        solve(idx+1,words,score,mp,ans,curr);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n=words.size();
        int ans=INT_MIN;
        int idx=0;
        vector<int>mp(26,0);

        for(auto& c:letters)
        {
            mp[c-'a']++;
        }
        int curr=0;
        solve(idx,words,score,mp,ans,curr);

        return ans;
    }
};