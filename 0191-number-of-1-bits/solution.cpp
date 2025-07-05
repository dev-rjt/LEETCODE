class Solution {
public:
    int hammingWeight(int n) {

        int sum = 0;

    while(n) {

        int x = n&1;
        sum = sum + x;
        n = n>>1;

    }

    return sum;
        
    }
};
