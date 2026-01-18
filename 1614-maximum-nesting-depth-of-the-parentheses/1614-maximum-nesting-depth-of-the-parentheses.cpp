class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int n=s.length();
        int ans=0;
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                cnt++;
                ans=max(ans,cnt);
                st.push('(');
            }else if(!st.empty() && s[i]==')')
            {
                st.pop();
                cnt--;
            }
        }
        return ans;
    }
};