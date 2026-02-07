class Solution {
public:
    int minimumDeletions(string s) {
        stack<int>st;
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!st.empty())
            {
                char top=st.top();
                char curr=s[i];
                if( !st.empty() && curr=='a' && top=='b')
                {
                    st.pop();
                    cnt++;
                }else{
                    st.push(curr);
                }
            }else{
                st.push(s[i]);
            }
        }
        return cnt;
    }
};