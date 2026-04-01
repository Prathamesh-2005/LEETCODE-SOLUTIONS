class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>tmp(n);

        for(int i=0;i<n;i++)
        {
            tmp[i]=i;
        }
        auto comp=[&](int a,int b)
        {
            return positions[a]<positions[b];
        };
        sort(tmp.begin(),tmp.end(),comp);

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            if(directions[tmp[i]]=='R')
            {
                st.push(tmp[i]);
            }else{
                while(!st.empty() && healths[tmp[i]]>0)
                {
                    int top=st.top();
                    st.pop();

                    if(healths[top]>healths[tmp[i]])
                    {
                        healths[top]-=1;
                        healths[tmp[i]]=0;
                        st.push(top);
                    }else if(healths[top]==healths[tmp[i]]){
                        healths[top]=0;
                        healths[tmp[i]]=0;
                    }else{
                        healths[tmp[i]]-=1;
                        healths[top]=0;
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(healths[i]>0)
            {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};