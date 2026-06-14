class Solution {
public:
    bool checkGoodInteger(int n) {
        int a = 0;
        int b = 0;

        while(n){
            int digit = n%10;
            a+=digit;
            b+=digit*digit;
            n/=10;
        }
        if(b-a>=50) return true;
        return false;
    }
};
