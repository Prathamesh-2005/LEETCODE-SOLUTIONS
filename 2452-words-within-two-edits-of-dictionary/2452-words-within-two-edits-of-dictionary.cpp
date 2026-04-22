class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        unordered_map<string,int>mp;
        int n=queries.size();
        int m=dictionary.size();

        for(int i=0;i<n;i++)
        {
            string curr=queries[i];
            for(int j=0;j<m;j++)
            {
                string dict=dictionary[j];
                if(curr==dict)
                {
                    if(mp.count(curr)==0)
                    {
                        ans.push_back(curr);
                        mp[curr]++;
                    }
                }else{
                    if(dict.length()!=curr.length())
                    {
                        continue;
                    }
                    int k=curr.length();
                    int cnt=0;
                    for(int p=0;p<k;p++)
                    {
                        if(curr[p]!=dict[p])
                        {
                            cnt++;
                        }
                    }
                    if(cnt<=2)
                    {
                        if(mp.count(curr)==0)
                        {
                            ans.push_back(curr);
                            mp[curr]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};