class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int i=num.length()-1;

        while(i>=0){
            int digit = num[i] + '0';
            if(digit%2) break;
            i--;
        }

        for(int j=0;j<=i;j++){
            ans.push_back(num[j]);
        }
        return ans;
    }
};
