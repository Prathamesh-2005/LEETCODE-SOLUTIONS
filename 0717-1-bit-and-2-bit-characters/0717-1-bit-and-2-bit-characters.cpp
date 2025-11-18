class Solution {
public:
    bool check(int i)
    {
        return (i==0);
    }
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                if(check(bits[i]))
                {
                    visit[i]=true;
                }
                if(!check(bits[i]) && i==n-1)
                {
                    return false;
                }

                if(!check(bits[i]))
                {
                    if(i==n-2)
                    {
                        if(check(bits[i+1]))
                        {
                            return false;
                        }
                    }
                    visit[i]=true;
                    visit[i+1]=true;
                }
            }
            
        }

        return true;
    }
};