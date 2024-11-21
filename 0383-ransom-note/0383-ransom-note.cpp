class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char ,int >count;

        for(auto c:magazine)
        {
            count[c]++;

        }

        for(auto c:ransomNote)
        {
            if(count[c]==0)
             return false;
              count[c]--;
        }
       

        return true;
    }
};