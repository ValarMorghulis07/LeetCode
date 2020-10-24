// 1344. Angle Between Hands of a Clock

// first find what hr makes with 12:00 then find what min makes with 12:00 ,then take the absolute diff.

class Solution {
public:

    double angleClock(int hour, int minutes) 
    {
     double hrangle=(hour%12)*30.0+(0.5*minutes);
     double minangle=minutes*6.0;
     double ans=abs(hrangle-minangle);
     return min(ans,360.0-ans); // 360.0-ans--->12:50
    }
};
