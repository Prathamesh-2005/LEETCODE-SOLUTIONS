class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int n=s.length();
        int i=0,j=0;
        string curr="";
        while(j<n)
        {
            curr+=s[j];
            if(j-i+1==k)
            {
                st.insert(curr);
            }
            while(i<n && j-i+1>k)
            {
                i++;
                curr.erase(curr.begin());
                if(j-i+1==k)
                {
                    st.insert(curr);
                }
            }
            j++;
        }

        for(auto& s:st)
        {
            cout<<s<<endl;
        }
        return st.size()==(1<<k);
    }
};