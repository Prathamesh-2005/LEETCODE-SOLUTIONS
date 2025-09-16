class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         int ans=0;
        priority_queue<int>pq1(g.begin(),g.end());
        priority_queue<int>pq2(s.begin(),s.end());

        while(!pq1.empty() && !pq2.empty())
        {
          if(pq1.top()<=pq2.top())
          {
            ans++;
            pq1.pop();
            pq2.pop();
          }else{
            pq1.pop();
          }
        }
        return ans;
    }
};