class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        ans.push_back({1});

        for(int i=0;i<numRows-1;i++){
            vector <int> temp = ans[i];
            vector <int> res;
            res.push_back(1);
            for(int j=0;j<temp.size()-1;j++){
                res.push_back(temp[j]+temp[j+1]);
            }
            res.push_back(1);
            ans.push_back(res);
        }

        return ans;


    }
};
