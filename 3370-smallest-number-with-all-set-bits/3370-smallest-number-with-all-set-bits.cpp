class Solution {
public:
    bool all(int i)
    {
        while(i>0)
        {
            if((i&1)==0)
            {
                return false;
            }
            i>>=1;
        }

        return true;
    }
    int smallestNumber(int n) {
        
        for(int i=n;i<=1000;i++)
        {
            if(all(i))
            {
                return i;
            }
        }

        return -1;
    }
};