class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=0;
        double hr=(double)hour+(double)(minutes/60.0);
        double hr_angle=hr*30;
        double min_angle=(minutes*6);
        ans=abs(hr_angle-min_angle);

        if(ans>180)
        {
            return 360-ans;
        }
        return ans;
    }
};