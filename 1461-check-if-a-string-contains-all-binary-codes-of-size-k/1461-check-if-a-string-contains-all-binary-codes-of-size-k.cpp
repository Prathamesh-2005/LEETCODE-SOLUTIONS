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
            if(curr.length()==k)
            {
                st.insert(curr);
                curr.erase(0,1);
            }
            j++;
        }

        for(auto& s:st)
        {
            cout<<s<<endl;
        }
        return st.size()==(int)(pow(2,k));
    }
};