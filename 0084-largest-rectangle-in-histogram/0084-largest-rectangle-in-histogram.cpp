class Solution {
public:
    vector<int> nsl(vector<int>& nums)
    {
        stack<int>st;
        int n=nums.size();
        vector<int>nl(n);

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            nl[i]=st.empty()?-1 :st.top();
            st.push(i);
        }
        return nl;
        
    }
       vector<int> nsr(vector<int>& nums)
    {
        stack<int>st;
        int n=nums.size();
        vector<int>nr(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            nr[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nr;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nl=nsl(heights);
        vector<int>nr=nsr(heights);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int width=nr[i]-nl[i]-1;
            int area=heights[i]*width;
            ans=max(ans,area);
        }
        return ans;
    }
};