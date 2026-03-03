class Solution {
public:
    string invert(string& str)
    {
        string ans="";
        for(auto& c:str)
        {
            if(c=='0')
            {
                ans+="1";
            }else{
                ans+="0";
            }
        }
        return ans;
    }
    char findKthBit(int n, int k) {
        string str="0";

        while(n>0)
        {
            string curr=invert(str);
            reverse(curr.begin(),curr.end());
            str= str+ "1" + curr;
            n--;
        }
        return str[k-1];
    }
};