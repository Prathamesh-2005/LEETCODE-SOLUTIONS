class Solution {
public:
    int count(string& str)
    {
        int ans=0;

        for(auto& c:str)
        {
            if(c=='1')
            {
                ans++;
            }
        }
        return ans;
    }
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();

        vector<int>vec;

        for(int i=0;i<n;i++)
        {
            int num=count(bank[i]);
            if(num!=0)
            {
                vec.push_back(num);
            }
        }

        int ans=0;
        for(int i=1;i<vec.size();i++)
        {
            int curr=vec[i];
            int prev=vec[i-1];
            int pro=curr*prev;
            ans+=pro;
        }
        return ans;
    }
};