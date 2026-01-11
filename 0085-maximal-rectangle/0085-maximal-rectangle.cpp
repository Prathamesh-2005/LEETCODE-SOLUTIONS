class Solution {
public:
    vector<int> nsl(vector<int>& mat)
    {
        int n=mat.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && mat[st.top()]>=mat[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nsr(vector<int>& mat)
    {
        int n=mat.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && mat[st.top()]>=mat[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int help(vector<int>& arr)
    {
        int ans=0;
        vector<int>nl=nsl(arr);
        vector<int>nr=nsr(arr);

        for(int i=0;i<arr.size();i++)
        {
            int width=nr[i]-nl[i]-1;
            int area=arr[i]*width;
            ans=max(ans,area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int>prefix(m,0);

        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    prefix[i]+=1;
                }else{
                    prefix[i]=0;
                }
            }
            ans=max(ans,help(prefix));
        }
        return ans;
    }
};