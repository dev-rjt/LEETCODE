class Solution {
public:
    int fib(int n) {

        if(n==0) return 0;
        if(n==1) return 1;
        int x = 0;
        int y= 1;
        int ans;

        for(int i=0;i<n-1;i++) {
            ans = x+y;
            x = y;
            y = ans;
        }

        return ans;
    }
};
