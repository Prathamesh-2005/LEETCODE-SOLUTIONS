class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans=s;
        queue<string>q;
        unordered_set<string>visited;
        q.push(s);
        visited.insert(s);

        while(!q.empty())
        {
            string curr=q.front();
            q.pop();

            if(curr<ans)
            {
                ans=curr;
            }

            string str=curr;

            for(int i=1;i<str.length();i+=2)
            {
                str[i]=((str[i]-'0'+a)%10)+'0';
            }

            if(visited.find(str)==visited.end())
            {
                visited.insert(str);
                q.push(str);
            }

            reverse(curr.begin(),curr.end());
            reverse(curr.begin(),curr.begin()+b);
            reverse(curr.begin()+b,curr.end());

            if(visited.find(curr)==visited.end())
            {
                visited.insert(curr);
                q.push(curr);
            }
        }

        return ans;
    }
};