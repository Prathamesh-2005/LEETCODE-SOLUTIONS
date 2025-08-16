class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);
        bool flag=true;
        int idx=0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='6' && flag)
            {
                idx=i;
                flag=false;
            }
        }
        str[idx]='9';
        num=stoi(str);

        return num;
    }
};