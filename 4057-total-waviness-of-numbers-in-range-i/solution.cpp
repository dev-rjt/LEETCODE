class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int ans = 0;

        for(int i=num1;i<=num2;i++){
            vector<int> digits;
            int num = i;

            while(num){
                digits.push_back(num%10);
                num/=10;
            }

            if(digits.size()<3) continue;
            
            int j = 0;

            while(digits.size()-j>=3){
                int a = digits[j];
                int b = digits[j+1];
                int c = digits[j+2];

                if(b>a && b>c || b<a && b<c){
                    ans++;
                }

                j++;

            }
        }

        return ans;
    }
};
