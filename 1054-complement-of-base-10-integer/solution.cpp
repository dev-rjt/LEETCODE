class Solution {
public:
    int bitwiseComplement(int n) {



    if(n!=0) {
    int ans=0;
    int i = 0;

    while(n){
        int bit = n&1;
        int a = !bit;

    
        if (a!=0) {
            ans = a*pow(2,i) + ans;

        }

        n = n>>1;
        i++;


    }

    return ans;
    }

    else {
        return 1;
    }
        
    }
};
