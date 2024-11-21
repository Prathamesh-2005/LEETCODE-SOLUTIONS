class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        map<char,int>m1;
        

        for(auto m:magazine)
        {
            m1[m]++;
        }

        for(auto m:ransomNote)
        {
            if(m1[m]==0)
            {
                return  false;
            }
            m1[m]--;
        }
        return true;
        
    }
};