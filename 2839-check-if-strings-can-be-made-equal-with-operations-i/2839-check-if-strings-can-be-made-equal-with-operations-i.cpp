class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string tmp1=s1;
        string tmp2=s2;

        if(s1[0]!=s2[0] && s1[2]!=s2[2])
        {
            swap(s1[0],s1[2]);
        }
        if(s1==s2)
        {
            return true;
        }
        if(s1[1]!=s2[1] && s1[3]!=s2[3])
        {
            swap(s1[1],s1[3]);
        }
        if(s1==s2)
        {
            return true;
        }

        if(tmp1[0]!=tmp2[0] && tmp1[2]!=tmp2[2])
        {
            swap(tmp1[0],tmp1[2]);
        }
        if(tmp1==tmp2)
        {
            return true;
        }

        if(tmp1[1]!=tmp2[1] && tmp1[3]!=tmp2[3])
        {
            swap(tmp1[1],tmp1[3]);
        }
        if(tmp1==tmp2)
        {
            return true;
        }
        return false;
    }
};