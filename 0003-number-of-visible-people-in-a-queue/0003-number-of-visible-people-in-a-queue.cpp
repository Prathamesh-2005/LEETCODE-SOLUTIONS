class Solution {
public:
    // void ngr(vector<int>& heights,vector<int>& vec)
    // {
    //     stack<int>st;
    //     int n=heights.size();

    //     for(int i=n-1;i>=0;i--)
    //     {
    //         while(!st.empty() && heights[st.top()]<=heights[i])
    //         {
    //             st.pop();
    //         }
    //         if(!st.empty())
    //         {
    //             vec[i]=st.top();
    //         }
    //         st.push(i);
    //     }
    // }
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n,0);
        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<heights[i])
            {
                ans[i]++;
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]++;
            }
            st.push(heights[i]);
        }
        return ans;
    }
};