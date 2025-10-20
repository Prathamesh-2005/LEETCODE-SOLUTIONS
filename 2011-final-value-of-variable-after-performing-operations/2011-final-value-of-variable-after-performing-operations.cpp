class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;

        for(auto& str:operations)
        {
            if(str[0]=='-')
            {
                --ans;
            }
            else if(str[0]=='+')
            {
                ++ans;
            }
            else if(str[1]=='-')
            {
                ans--;
            }
            else{
                ans++;
            }
        }

        return ans;
    }
};