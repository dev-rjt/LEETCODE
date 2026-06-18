class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle1 = 6*minutes;

        double angle2 = ((double)0.5)*(hour*60+minutes);
        if(angle2>=360) angle2-=360;
        
        return min(abs(angle2-angle1),360-(abs(angle2-angle1)));
    }
};
