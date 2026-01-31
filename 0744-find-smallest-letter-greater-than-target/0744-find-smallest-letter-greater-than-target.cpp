class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        char ans=letters[0];

        for(auto& c:letters)
        {
            if(c>target)
            {
                ans=c;
                break;
            }
        }

        return ans;
    }
};