class Solution {
    public boolean solve(int[] stones,Map<Integer,Integer>mp,int curr_idx,int prev_jmp,int n,Boolean [][]dp)
    {
        if(curr_idx==n-1)
        {
            return true;
        }
        if(dp[curr_idx][prev_jmp]!=null)
        {
            return dp[curr_idx][prev_jmp];
        }

        for(int i=prev_jmp-1;i<=prev_jmp+1;i++)
        {
            if(i>0)
            {
                int next=stones[curr_idx]+i;
                if(mp.containsKey(next))
                {
                    if(solve(stones,mp,mp.get(next),i,n,dp))
                    {
                        return dp[curr_idx][prev_jmp]= true;
                    }
                }
            }
        }
        return dp[curr_idx][prev_jmp]=false;
    }
    public boolean canCross(int[] stones) {
        int n=stones.length;
        Boolean [][]dp=new Boolean[n][n];
        if(stones[1]!=1)
        {
            return false;
        }
        Map<Integer,Integer>mp=new HashMap<>();
        // int n=stones.length;

        for(int i=0;i<n;i++)
        {
            mp.put(stones[i],i);
        }
        return solve(stones,mp,0,0,n,dp);
    }
}