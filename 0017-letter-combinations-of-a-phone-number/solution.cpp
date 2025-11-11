class Solution {
public:
    void solve(vector<string> &ans,string output,string mapping[],int index,string digits) {
        //base case
        if(index==digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value  = mapping[number];

        for(int i=0;i<value.length();i++) {
            output.push_back(value[i]);
            solve(ans,output,mapping,index+1,digits);
            output.pop_back();
        } 
        
    }
    vector<string> letterCombinations(string digits) {
        int index = 0;
        vector <string> ans;
        string output;
        string mapping[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(ans,output,mapping,index,digits);
        return ans;
    }
};
