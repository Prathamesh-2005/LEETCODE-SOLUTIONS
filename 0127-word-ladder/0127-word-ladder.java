class Pair{
    String first;
    int second;

    Pair(String first,int second)
    {
        this.first=first;
        this.second=second;
    }
}
class Solution {
    public int ladderLength(String begin, String end, List<String> wordList) {
        Queue<Pair>q=new LinkedList<>();
        q.add(new Pair(begin,1));
        Set<String> st=new HashSet<>();

        for(String str:wordList)
        {
            st.add(str);
        }
        st.remove(begin);

        while(!q.isEmpty())
        {
            String word=q.peek().first;
            int step=q.peek().second;
            q.poll();
            
            if(word.equals(end))
            {
                return step;
            }

            for(int i=0;i<word.length();i++)
            {
                char [] arr=word.toCharArray();
                char org=arr[i];

                for(char ch='a';ch<='z';ch++)
                {
                    arr[i]=ch;
                    String str=new String(arr);

                    if(st.contains(str))
                    {
                        st.remove(str);
                        q.add(new Pair(str,step+1));
                    }
                }
                arr[i]=org;
            }
        }
        return 0;
    }
}