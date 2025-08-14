class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int n=num.size();
        for(int i=2;i<n;i++)
        {
            if(num[i]==num[i-1] && num[i]==num[i-2])
            {
                string temp=string(3,num[i]);
                if(temp>ans)
                ans=temp;
            }
        }
        return ans;
    }
};