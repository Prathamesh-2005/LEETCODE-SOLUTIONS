class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.length();

        int left{0},right{0},under{0};

        for(auto& c:moves)
        {
            if(c=='L')
            {
                left++;
            }else if(c=='R')
            {
                right++;
            }else{
                under++;
            }
        }
        
        return abs(left-right)+under;
    }
};