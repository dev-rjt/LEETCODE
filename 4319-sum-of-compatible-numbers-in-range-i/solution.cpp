class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        
        for(int i=0;i<=(n+k);i++){
            if(abs(n-i)<=k && !(i&n)) sum+=i;
        }

        return sum;
    }
};
