#define ll long long
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod=1e9+7;
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        ll side=0;
        unordered_set<int>st1;
        for(int i=0;i<hFences.size();i++)
        {
            for(int j=i+1;j<hFences.size();j++)
            {
                st1.insert(hFences[j]-hFences[i]);
            }
        }
        for(int i=0;i<vFences.size();i++)
        {
            for(int j=i+1;j<vFences.size();j++)
            {
                if(st1.find(vFences[j]-vFences[i])!=st1.end())
                {
                    side=max(side,(ll)vFences[j]-vFences[i]);
                }
            }
        }

        if(side==0)
        {
            return -1;
        }else{
            return (side*side)%mod;
        }
    }
};