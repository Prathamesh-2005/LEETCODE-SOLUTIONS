class Solution { 
    int [] idx=new int [2];
    boolean check(List<Long> nums)
    {
        idx[0]=-1;
        idx[1]=-1;
        int n=nums.size();

        for(int i=1;i<n;i++)
        {
            if(nums.get(i).equals(nums.get(i-1)))
            {
                idx[0]=i-1;
                idx[1]=i;
                return true;
            }
        }
        return false;
    }
    public List<Long> mergeAdjacent(int[] nums) {
        List<Long>ans=new ArrayList<>();
        int n=nums.length;
        Stack<Long>st=new Stack<>();
        for(int num:nums)
        {
            if(!st.isEmpty() && st.peek().equals((long)num))
            {
                long sum=st.pop()+num;
                while(!st.isEmpty() && st.peek().equals((long)sum))
                {
                    sum+=st.pop();
                }
                st.push(sum);
            }else{
                st.push((long)num);
            }
        }

        while(!st.isEmpty())
        {
            ans.add(st.pop());
        }
        Collections.reverse(ans);
        return ans;
    }
}