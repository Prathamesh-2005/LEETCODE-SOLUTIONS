class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=1;i<n;i++)
        {
            int x2=points[i][0];
            int y2=points[i][1];
            int x1=points[i-1][0];
            int y1=points[i-1][1];

            while(x1!=x2 && y1!=y2)
            {
                if(x2>x1)
                {
                    x1++;
                }else{
                    x1--;
                }

                if(y2>y1){
                    y1++;
                }else{
                    y1--;
                }
                ans++;
            }

            ans+=abs(y2-y1);
            ans+=abs(x2-x1);
        }
        return ans;
    }
};