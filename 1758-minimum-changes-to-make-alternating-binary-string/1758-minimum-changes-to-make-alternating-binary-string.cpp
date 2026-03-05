class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int ans1=0;
        vector<int>vec1(n);
        vector<int>vec2(n);

        for(int i=0;i<n;i++)
        {
            if(i & 1)
            {
                vec1[i]=1;
            }else{
                vec1[i]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i & 1)
            {
                vec2[i]=0;
            }else{
                vec2[i]=1;
            }
        }

        int ans2=0;
        for(int i=0;i<n;i++)
        {
            if(vec1[i]!=s[i]-'0')
            {
                ans1++;
            }
            if(vec2[i]!=s[i]-'0')
            {
                ans2++;
            }
        }
        
        return min(ans1,ans2);
    }
};