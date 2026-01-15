class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int len=1;
        int vert=1;
        int horz=1;

        for(int i=1;i<hBars.size();i++)
        {
            if(hBars[i-1]+1==hBars[i])
            {
                len++;
            }else{
                len=1;
            }
            horz=max(horz,len);
        }

        cout<<horz<<endl;

        len=1;

        for(int i=1;i<vBars.size();i++)
        {
            if(vBars[i-1]+1==vBars[i])
            {
                len++;
            }else{
                len=1;
            }
            vert=max(vert,len);
        }

        cout<<vert<<endl;
        int side=min(horz,vert)+1;

        return side*side;
    }
};