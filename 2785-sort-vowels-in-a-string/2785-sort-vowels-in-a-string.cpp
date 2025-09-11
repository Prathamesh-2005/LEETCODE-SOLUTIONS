class Solution {
public:
    bool isvowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A'  || c=='E' || c=='I' || c=='O' || c=='U');
    }
    string sortVowels(string s) {
        string ans=s;
        int n=s.length();
        vector<char>vow;
        
        for(int i=0;i<n;i++)
        {
            if(isvowel(s[i]))
            {
                vow.push_back(s[i]);
            }
        }
        sort(vow.begin(),vow.end());
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(j<vow.size() && isvowel(s[i]))
            {
                ans[i]=vow[j];
                j++;
            }
        }
        return ans;
    }
};