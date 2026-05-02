class Solution {
public:
    bool check(string& num)
    {
        string s="";

        for(auto& c:num)
        {
            if(c=='0' || c=='1' || c=='8')
            {
                s+=c;
            }else if(c=='2')
            {
                s+='5';
            }else if(c=='5')
            {
                s+='2';
            }else if(c=='6')
            {
                s+='9';
            }else if(c=='9')
            {
                s+='6';
            }else{
                return false;
            }
        }
        if(s==num)
        {
            return false;
        }
        return true;
    }
    
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            string num=to_string(i);
            if(check(num))
            {
                ans++;
            }
        }
        return ans;
    }
};