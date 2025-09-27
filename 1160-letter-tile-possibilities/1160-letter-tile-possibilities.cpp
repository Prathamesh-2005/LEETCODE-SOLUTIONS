class Solution {
public:
    void solve(string s,vector<bool>&used,unordered_set<string>&res,string &curr)
    {
        res.insert(curr);
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            if(used[i])
            {
                continue;
            }
            used[i]=true;
            curr.push_back(s[i]);
            solve(s,used,res,curr);
            used[i]=false;
            curr.pop_back();
        }

    }
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        vector<bool>used(n,false);
        unordered_set<string>res;
        string curr="";
        solve(tiles,used,res,curr);

        return res.size()-1;
    }
};