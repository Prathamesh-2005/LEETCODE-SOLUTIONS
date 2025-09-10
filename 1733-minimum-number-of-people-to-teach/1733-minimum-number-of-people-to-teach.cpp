class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=friendships.size();
        int ans=0;
        int cnt=0;
        unordered_set<int>st;
        for(int i=0;i<m;i++)
        {
            int u=friendships[i][0]-1;
            int v=friendships[i][1]-1;
            unordered_set<int>tmp(languages[u].begin(),languages[u].end());

            bool flag=false;

            for(auto& l:languages[v])
            {
                if(tmp.find(l)!=tmp.end())
                {
                    flag=true;
                    break;
                }
            }

            if(!flag)
            {
                st.insert(u);
                st.insert(v);
            }
        }

        unordered_map<int,int>mp;

        for(auto& s:st)
        {
            for(auto& m:languages[s])
            {
                mp[m]++;
            }
        }
        int mx=0;

        for(auto& m:mp)
        {
            mx=max(mx,m.second);
        }
        return st.size()-mx;
    }
};