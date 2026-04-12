class Solution {
public:
    typedef double d;
    vector<double> internalAngles(vector<int>& sides) {
        vector<d>ans;
        int n=sides.size();
        int a=sides[0];
        int b=sides[1];
        int c=sides[2];

        if(a+b<=c && b+c<=a && a+c<=a)
        {
            return {};
        }
        int angle1=((b*b)+(c*c)-(a*a))/(2*b*a);
        int angle2=((a*a)+(c*c)-(b*b))/(2*a*c);
        int angle3=((a*a)+(b*b)-(c*c))/(2*b*a);
        
        angle1=(angle1)*(180/3.14);
        angle2=(angle2)*(180/3.14);
        angle3=(angle3)*(180/3.14);
        ans[0]=angle1;
        ans[1]=angle2;
        ans[2]=angle3;

        sort(ans.begin(),ans.end());
        return ans;
    }
};